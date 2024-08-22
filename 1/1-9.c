// copyright
#include <stdio.h>

int main() {
  int  c;
  while ((c = getchar()) != EOF) {
    if (c != ' ') {
      putchar(c);
    }
    if (c == ' ') {
      putchar(c);
      while ((c = getchar()) == ' ') {}
    }
  }
  return 0;
}
