/**
 * @file session.cpp
 *
 * Testing a session class. Which gives how long is a session.
*/

#include <iostream>
#include <ctime>
#include <cassert>
#include <unistd.h>

class Session {
public:
	Session() : start_time(std::time(nullptr)) {}
	int elapsed() { return std::time(nullptr) - start_time; }
private:
	std::time_t start_time;
};

int main() {

	{
		Session s;
		// Wait two seconds
		sleep(2);
		assert(s.elapsed() == 2);
	}

	/* remember testing typical is a high-value test
	 * but what is typical, what if it is hour(s)
	 * Can your afford to wait an hour each time you make a change?
	 */

	{
		Session s;
		// Wait an hour
		sleep(3600);
		assert(s.elapsed() == 3600);
	}


	return 0;
}
