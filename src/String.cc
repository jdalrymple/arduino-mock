#include "String.h"

static StringMock* gStringMock = NULL;

StringMock* stringMockInstance() {
  if(!gStringMock) {
    gStringMock = new StringMock();
  }
  return gStringMock;
}

void releaseStringMock() {
  if(gStringMock) {
    delete gStringMock;
    gStringMock = NULL;
  }
}

// String String_::substring(int start) {
//   gStringMock->substring(start);
// }

// String String_::substring(int start, int end) {
//   gStringMock->substring(start, end);
// }

// String String_::remove(int start) {
//   gStringMock->remove(start);
// }

int String_::indexOf(const char needle) {
  gStringMock->indexOf(needle);
}

// Preinstantiate Objects
String_ String;
