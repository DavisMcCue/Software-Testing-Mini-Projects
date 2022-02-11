# Report:

# What is the statement-coverage for that constructor/method?
Constructor 

String::String(): 100.00 Coverage; <br>
String::String(const char * cstr): 100.00 Coverage;<br>
String::capacity() const: 100.00 Coverage;<br>
String::length() const: 100.00 Coverage;<br>

Methods

String::operator+(const String & rhs) const: 100.00 Coverage;<br>
String::operator==(const String & rhs) const: 80.00 Coverage;<br>
main (): 100.00 Coverage;<br>
String::operator<<(std::ostream & out, const String & rhs): 100.00 Coverage;<br><br>

# What does the statement-coverage tell you about the tests?

<p> It tells us that the test code that was set up atleast reached each of the constructor/methods <br>
atleast once during it execution. I feel like it is hard to see the quality of the test
based on the coverage. <br> I mean if it is 100% coverage I would assume the quality of the test 
is good. Where if it is 10% coverage <br> then it is not good at all. I feel like the "flow" of code 
going into the methods or constructors is based on <br> the coverage we see for each constructor/methods 
and when it is a low precentage that means the flow is <br> not working correctly and when it is high precentage 
it means that it is working correctly. </p> <br>


# From a black-box perspective (looking at test file only), is there  <br> a strong  set of tests?

### Test_cstring.cpp 

<p> I would say based on looking at the above cpp file. I would stay the test are okay. I wouldn't say there <br>
"strong". I feel at one point that in the verify section that the asserts are testing themselves so, the tests <br> 
are not strong. I would say some of the tests are strong but, other tests within the cpp file should be <br> stronger 
I feel </p>

### test_concat.cpp

<p> I would say that in the above cpp file that these are strong tests because it coverage a wide variety of <br> 
ranges for the tests. </p>

### test_equality.cpp

<p> I would say personality that I think these are the best or have the strongest tests because of what it is <br> 
testing and the wide range it is testing.

# Is the statement-coverage giving an accurate measure of test <br> quality? 

<p> I would say that the statement-coverage is not giving an accurate measurement of testing quality. It has High 
<br> coverage but I think the tests are weak written and need to do more advance testing because all the statement <br> 
-coverage is telling us is that data we want is reaching the constructor/methods and how often the flow of data <br> is 
touching those constructor/methods so, I would say it is HIGH coverage but, tests are poor   </p>