#include "string.hpp"


String::String() {
  string_size = 1;
  str = new char[string_size];
  str[0] = '\0';
}

String::String(char ch) {
  string_size = 2;
  str = new char[string_size];
  str[0] = ch;
  str[1] = '\0';
}

String::String(const char cString[]) {
  int len = 0;
  while (cString[len] != '\0') {
    ++len;
  }
  
  string_size = len + 1;
  str = new char[string_size];
  
  for (int i = 0; i < len; ++i) {
    str[i] = cString[i];
  }

  str[len] = '\0';
}

String::String(const String& other) {
  string_size = other.string_size;
  str = new char[string_size];

  int index = 0;  
  while (other.str[index] != '\0') {
    str[index] = other.str[index];
    ++index;
  }
  
  str[index] = other.str[index];
}

String::String(int size) {
  string_size = size;
  str = new char[string_size];
  str[0] = '\0';
}

String::String(int size, const char* other) {
  string_size = size;
  str = new char[string_size];

  int index = 0;
  while (other[index] != '\0') {
    str[index] = other[index];
    ++index;
  }
  
  str[index] = other[index];
}

String::~String(){
  delete[] str;
}

void String::reset_capacity (int size) {
  char* temp = str;
  string_size = size;
  str = new char[string_size];
  
  int index = 0;
  while (temp[index] != '\0') {
    str[index] = temp[index];
    ++index;
  }

  str[index] = temp[index];
  delete[] temp;
}

int String::capacity() const {
  return string_size - 1;
}

int String::length() const {
  int len = 0;
  
  while(str[len] != '\0') {
    ++len;
  }
  
  return len;
}

String String::substr(int start_pos, int count) const {  
  int str_len = length();
  String sub;

  for (int i = 0; i < count; ++i) {
    if ((start_pos + i) > str_len)
      break;

    sub += str[start_pos + i];
  }

  return sub;
}


std::vector<String> String::split(char delim) const {
  int str_len = length();
  String temp;
  std::vector<String> fields;

  for (int i = 0; i < str_len; ++i) {
    if (str[i] == delim) {
      fields.push_back(temp);
      temp = "";
      continue;
    }
    temp += str[i];
  }

  fields.push_back(temp);
  return fields;
}

int String::find(char ch, int start_pos) const {
  int pos = -1;
  
  if (start_pos >= length())
    return pos;

  for (int i = start_pos; i < length(); ++i) {
    if (str[i] == ch) {
      pos = i;
      break;
    }
  }

  return pos;
}

int String::find(const String & s, int start_pos) const {
  int pos = find(s.str[0], start_pos);
  bool found = false;
  int sub_len = s.length();

  while (pos != -1) {

    for (int i = 0; i < sub_len; ++i) {
      if (str[pos + i] != s[i])
	break;

      if (i == (sub_len - 1))
	found = true;
    }
 
   if (found)
      break;

    pos = find(s.str[0], pos + 1);
  }
  return pos;
}

void String::swap(String& other) {
  char* temp = str;
  str = other.str;
  other.str = temp;

  int temp_size = string_size;
  string_size = other.string_size;
  other.string_size = temp_size;
}

String& String::operator=(String rhs) {
  swap(rhs);
  return *this;
}

bool String::operator==(const String& rhs) const {
  int index = 0;
  
  while (str[index] != '\0' && rhs.str[index] != '\0') {
    if (str[index] != rhs.str[index]) {
      return false;
    }
    ++index;
  }

  return str[index] == rhs.str[index];
}

bool String::operator< (const String& rhs)  const {
  int index = 0;
  
  while (str[index] != '\0' && rhs.str[index] != '\0' && str[index] == rhs.str[index]) {
    ++index;
  }

  return str[index] < rhs.str[index];
}


String String::operator+ (const String& rhs) const {
  int offset = length();

  String result = String((offset + rhs.length() + 1), str);
  
  int index = 0;
  while (rhs.str[index] != '\0') {
    result.str[offset] = rhs.str[index];
    ++offset;
    ++index;
  }

  result.str[offset] = rhs.str[index];
  
  return result;
}


String& String::operator+=(String rhs) {
  int offset = length();
  reset_capacity(offset + rhs.length() + 1);

  int index = 0;
  while(rhs.str[index] != '\0') {
    str[offset] = rhs.str[index];
    ++offset;
    ++index;
  }

  str[offset] = rhs.str[index];
  return *this;
}


char& String::operator[](int index) {
  return str[index];
}

char String::operator[](int index) const {
  return str[index];
}

std::ostream& operator<<(std::ostream& out, const String& data) {
  for (int i = 0; i < data.length(); ++i) {
    out << data[i];
  }
  return out;
}

std::istream& operator>>(std::istream& in, String& word) {
  word = "";
  char raw_data[256];
  
  if (in >> raw_data) {
    word = String(raw_data);
  }
 
  return in;
}

String operator+ (const char* lhs, const String& rhs) {
  return String(lhs) + rhs;
}

String operator+ (char lhs, const String& rhs) {
  return String(lhs) + rhs;
}

bool operator== (const char* lhs, const String& rhs) {
  return String(lhs) == rhs;
}

bool operator== (char lhs, const String& rhs) {
  return String(lhs) == rhs;
}

bool operator< (const char* lhs, const String& rhs) {
  return String(lhs) < rhs;
}

bool operator< (char lhs, const String& rhs) {
  return String(lhs) < rhs;
}

bool operator<= (const String& lhs, const String& rhs) {
  if (lhs == rhs || lhs < rhs) {
    return true;
  }

  return false;
}

bool operator!= (const String& lhs, const String& rhs) {
  return (!(lhs == rhs));
}

bool operator>= (const String& lhs, const String& rhs) {
  return (!(lhs < rhs));
}

bool operator> (const String& lhs, const String& rhs) {
  return (!(lhs <= rhs));
}
