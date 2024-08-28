// copyright
#include <stdio.h>

// this program is getting more and more complex, the more you think about it
// hard to tell the sweet spot between coverage and effort
int main() {  // doesn't handle well comments after some code like this one
  int c;
  int previous = getchar();
  while ((c = getchar()) != EOF) {
    if (c == '/' && previous == '/') {
      while ((c = getchar()) != EOF && c != '\n') {
      }
      if (c == '\n') {
        c = getchar();
      }
    } else {
      putchar(previous);
    }
    previous = c;
  }

  if (previous != EOF) {  // handle the getchar() before the while loop
    putchar(previous);
  }
  return 0;
}

