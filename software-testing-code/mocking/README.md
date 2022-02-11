* `session.cpp` - Session class which uses a real time clock, illustrates the need for mocking
* `session_clock.cpp` - Make session use an abstract clock and provide a real time clock for production code and a configurable (mock) clock for testing.  Same session code tested, without waiting
* `test_session.cpp` - Use a mocking framework (Turtle) to autogenerate and provide more sophisticated verification
