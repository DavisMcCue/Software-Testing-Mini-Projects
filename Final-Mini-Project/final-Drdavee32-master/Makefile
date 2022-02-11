all: test

test_reverse: test_reverse.cpp reverse.cpp reverse.hpp
	clang++ test_reverse.cpp reverse.cpp -o test_reverse

test: test_reverse
	./test_reverse

clean:
	rm -f test_reverse
