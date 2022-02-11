/**
 * @file coverage.cpp
 *
 * Client to instrument a program in srcML with coverage collecing information.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include <iostream>
#include <string>
#include "coverage_handler.hpp"
#include <srcSAXController.hpp>

const int MAIN_POS = 1;
const std::string XML_STR = ".xml";

int main(int argc, char * argv[]) {

    for(int i = 1; i < argc; ++i) {

        std::string input_filename(argv[i]);

        try {

            srcSAXController control(input_filename.c_str());

            std::string output_filename = input_filename;
            output_filename = "c-" + output_filename.erase(input_filename.rfind(XML_STR));
            coverage_handler handler(i == MAIN_POS ? true : false, output_filename); 

            control.parse(&handler);


        } catch(SAXError & e) {
            std::cerr << "An error occurred parsing file: " << input_filename << '\n';
            std::cerr << e.message << '\n';
        }

    }

    return 0;
}
