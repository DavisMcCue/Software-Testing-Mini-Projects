all: test

test_palindrome: test_palindrome.cpp palindrome.cpp palindrome.hpp
	clang++ test_palindrome.cpp palindrome.cpp -o test_palindrome

test: test_palindrome
	./test_palindrome

clean:
	rm -f test_palindrome
