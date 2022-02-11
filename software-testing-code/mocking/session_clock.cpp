/**
 * @file session_clock.cpp
 *
 *	An example of Mock objects
 */

#include <iostream>
#include <ctime>
#include <cassert>
#include <unistd.h>

class Clock {
public:
	virtual std::time_t start() const = 0;
	virtual std::time_t now() const = 0;
};

class TimeClock : public Clock {
public:
	virtual std::time_t start() const { return now(); }
	virtual std::time_t now() const { return std::time(nullptr); }
};

class OneHourClock : public Clock {
public:
	virtual std::time_t start() const { return 0; }
	virtual std::time_t now() const { return 3600; }
};

class ConfigurableClock : public Clock {
public:
	ConfigurableClock(std::time_t amount) : length(amount) {}

	virtual std::time_t start() const { return 0; }
	virtual std::time_t now() const { return length; }
private:
	std::time_t length;
};

/**
 * Problem with testing lies with time to test.  Instead of using
 * a real clock, we can simulate a clock using mock objecs
 * Lets start by rewriting Session to take a clock object (abstract).
 * We add a normal time clock, for real-clock behavior.
 * Now we can add other clocks such as an hour clock or a configurable time clock.
 */
class Session {
public:
	Session(const Clock& clock) : clock(clock), start_time(clock.start()) {}
	int elapsed() { return clock.now() - start_time; }
private:
	const Clock& clock;
	std::time_t start_time;
};

int main() {

	{
		TimeClock c;
		Session s(c);

		sleep(2);

		assert(s.elapsed() == 2);
	}

	{
		OneHourClock c;
		Session s(c);

		assert(s.elapsed() == 3600);
	}

	{
		// This is seconds in a day (not testable otherwise)
		ConfigurableClock c(86400);
		Session s(c);

		assert(s.elapsed() == 86400);
	}

	return 0;
}
