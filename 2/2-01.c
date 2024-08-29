// copyright
#include <stdio.h>
#include <limits.h>
#include <float.h>

// printing just a few constants
int main() {
  // limits.h
  printf("CHAR_BIT:  %5d\n", CHAR_BIT);
  printf("SCHAR_MIN: %5d\n", SCHAR_MIN);
  printf("SCHAR_MAX: %5d\n", SCHAR_MAX);
  printf("UCHAR_MAX: %5d\n", UCHAR_MAX);
  printf("CHAR_MIN:  %5d\n", CHAR_MIN);
  printf("CHAR_MAX:  %5d\n", CHAR_MAX);
  printf("\n");

  // float.h
  printf("base: %d\n", FLT_RADIX);
  printf("maximum value of float: %.10e\n", FLT_MAX);
  printf("minimum value of float: %.10e\n", FLT_MIN);
  return 0;
}

