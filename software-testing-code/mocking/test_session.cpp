/**
 * @file test_session.cpp
 *
 *	Apply Turtle to testing a Session
 */

#define BOOST_TEST_MODULE test session
#include <boost/test/included/unit_test.hpp>
#include <turtle/mock.hpp>

#include <iostream>
#include <ctime>
#include <cassert>
#include <unistd.h>

class Clock {
public:
	virtual std::time_t start() const = 0;
	virtual std::time_t now() const = 0;
};

class Session {
public:
	Session(const Clock& clock) : clock(clock), start_time(clock.start()) {}
	int elapsed() { return clock.now() - start_time; }
private:
	const Clock& clock;
	std::time_t start_time;
};

MOCK_BASE_CLASS(mock_clock, Clock) {
    MOCK_METHOD(start, 0);
    MOCK_METHOD(now, 0);
};

BOOST_AUTO_TEST_CASE(zero) {

    // create mock object
    mock_clock c;

    // must have expect before it is called
    mock::sequence seq;
    MOCK_EXPECT(c.start).once().in(seq).returns(0);
    MOCK_EXPECT(c.now).once().in(seq).returns(0);

    // create object under test
    Session s(c);

    // excercise object under test
    //s.elapsed();
    BOOST_TEST(s.elapsed() == 0);
}

BOOST_AUTO_TEST_CASE(hour) {

    // create mock object
    mock_clock c;

    // must have expect before it is called
    mock::sequence seq;
    MOCK_EXPECT(c.start).once().in(seq).returns(0);
    MOCK_EXPECT(c.now).once().in(seq).returns(3600);

    // create object under test
    Session s(c);

    // excercise object under test
    BOOST_TEST(s.elapsed() == 3600);
}
