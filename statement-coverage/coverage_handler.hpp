/**
 * @file coverage_handler.hpp
 *
 * @copyright Copyright (C) 2017 srcML, LLC. (www.srcML.org)
 *
 * srcSAX is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * srcSAX is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the srcML Toolkit; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef INCLUDED_COVERAGE_HANDLER_HPP
#define INCLUDED_COVERAGE_HANDLER_HPP

#include <srcSAXHandler.hpp>
#include <fstream>
#include <string>

/**
 * coverage_handler
 *
 * Instrument code with coverage information.
 */
class coverage_handler : public srcSAXHandler {

private :

    bool is_main_file;
    std::ofstream out;
    std::string method_source;

    bool in_function;
    bool in_function_block;
    bool collect_name;
    bool in_condition;

    std::string function_content;
    std::string name_content;
    size_t num_elements;

public :

    /**
     * coverage_handler
     *
     * Default constructor default values to everything
     */
    coverage_handler(bool is_main_file, const std::string & out_filename)
        : srcSAXHandler(), is_main_file(is_main_file), out(out_filename.c_str()), method_source(),
          in_function(false), in_function_block(false), collect_name(false), in_condition(false),
          function_content(), name_content(),
          num_elements(0) {}

    /**
     * startUnit
     * @param localname the name of the element tag
     * @param prefix the tag prefix
     * @param URI the namespace of tag
     * @param num_namespaces number of namespaces definitions
     * @param namespaces the defined namespaces
     * @param num_attributes the number of attributes on the tag
     * @param attributes list of attributes
     *
     * SAX handler function for start of an unit.
     * Overide for desired behaviour.
     */
    virtual void startUnit(const char * localname, const char * prefix, const char * URI,
                           int num_namespaces, const struct srcsax_namespace * namespaces, int num_attributes,
                           const struct srcsax_attribute * attributes) {

        out << "#include \"coverage_map.hpp\"\n";
        if(is_main_file) {
            out << "coverage_map_t coverage_map;\n";
        } else {
            out << "extern coverage_map_t coverage_map;\n";
        }


    }

    /** 
     * is_func_type
     * @param tag_name the name of a tag (fully-prefixed)
     *
     * Helper function to identify if tag is of function type (i.e., function, constructor, or destructor).
     */
    static bool is_func_type(const std::string & tag_name) {
    	if(tag_name == "function")    return true;
       	if(tag_name == "constructor") return true;
   	    if(tag_name == "destructor")  return true;
    	return false;
    }

    /**
     * startElement
     * @param localname the name of the element tag
     * @param prefix the tag prefix
     * @param URI the namespace of tag
     * @param num_namespaces number of namespaces definitions
     * @param namespaces the defined namespaces
     * @param num_attributes the number of attributes on the tag
     * @param attributes list of attributes
     *
     * SAX handler function for start of an element.
     * Overide for desired behaviour.
     */
    virtual void startElement(const char * localname, const char * prefix, const char * URI,
                                int num_namespaces, const struct srcsax_namespace * namespaces, int num_attributes,
                                const struct srcsax_attribute * attributes) {
        std::string tag;
        if(prefix) {
            tag = std::string(prefix) + ":";
        }
        tag += localname;

        if(is_func_type(tag)) {
            in_function = true;
        }

        if(!in_function) return;

        if(is_func_type(get_stack().back())) {

            if(tag == "name") {
                collect_name = true;
            } else if(tag == "block") {
                collect_name = false;
                name_content.erase(name_content.find_last_not_of(" \n\r\t") + 1);
                in_function_block = true;                
            }
        }

        if(tag == "condition" && get_stack().back() != "ternary") {
            in_condition = true;
        }

        if(is_main_file && name_content.find("main") == 0 && tag == "return") {
            function_content += "coverage_map.print();";
        }

    }

    /**
     * endElement
     * @param localname the name of the element tag
     * @param prefix the tag prefix
     * @param URI the namespace of tag
     *
     * SAX handler function for end of an element.
     * Overide for desired behaviour.
     */
    virtual void endElement(const char * localname, const char * prefix, const char * URI) {

        std::string tag;
        if(prefix) {
            tag = std::string(prefix) + ":";
        }
        tag += localname;

        if(is_func_type(tag)) {
            in_function = false;
            in_function_block = false;

            out << function_content[0];
            out << "coverage_map.append(\"" << name_content << "\", " << num_elements << ");";
            out << &function_content.c_str()[1];

            function_content.clear();
            name_content.clear();
            num_elements = 0;
        }

        if(!in_function) return;

        if(tag == "name" && is_func_type(get_stack().back())) {
            //collect_name = false;
            return;
        }

        if(tag == "expr_stmt" || tag == "decl_stmt") {
            function_content += "coverage_map.executed(\"" +  name_content + "\", " + std::to_string(num_elements) + ");";
            ++num_elements;
        }

    }

    /**
     * charactersUnit
     * @param ch the characers
     * @param len number of characters
     *
     * SAX handler function for character handling within a unit.
     * Overide for desired behaviour.
     */
    virtual void charactersUnit(const char * ch, int len) {

        if(collect_name) {
            name_content.append(ch, len);
        }

        if(in_condition) {

            if(len > 0 && ch[0] == '(')  {
                function_content += '(';
                --len;
                ++ch;
            }
            function_content += "coverage_map.executed(\"" +  name_content + "\", " + std::to_string(num_elements) + "), ";
            ++num_elements;
            function_content.append(ch, len);
            in_condition = false;

        } else if(in_function_block) {

            function_content.append(ch, len);

        } else {

            std::string source;
            source.append(ch, len);
            out << source;

        }

    }

};

#endif
