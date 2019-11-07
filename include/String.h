/**
 * Arduino Spark mock
 */
#ifndef STRING_H
#define STRING_H

#include <stdint.h>
#include <gmock/gmock.h>

class StringMock {
  public:
    MOCK_METHOD1(indexOf, int (const char needle));
};

class String_ : public std::string {
 public:
  String_() {}
  String_(const String_& string) : String_(string.c_str()) {}
  String_(const std::string& string) : std::string(string) {}
  String_(const char* string) : std::string(string) {}

  // String_ substring(int start) {
  //   return substr(start);
  // }
  // String_ substring(int start, int end) {
  //   return substr(start, end-start);
  // }

  // String_ remove(int start) {
  //   return erase(start);
  // }

  int indexOf(const char needle);
};

extern String_ String;

StringMock* stringMockInstance();
void releaseStringMock();

#endif // STRING_H
