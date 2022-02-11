all: coverage

coverage: coverage.cpp coverage_handler.hpp
	g++ -std=c++11 -I /usr/local/include/srcsax -I /usr/include/libxml2/ -L /usr/local/lib/ coverage.cpp -lsrcsax -o coverage

clean: 
	rm -f coverage;
