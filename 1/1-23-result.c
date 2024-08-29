#include <stdio.h>



int main() {
  int c;
  int previous = getchar();

  while ((c = getchar()) != EOF) {
    if (c == '/' && previous == '/') {
      while ((c = getchar()) != EOF && c != '\n') {
      }
            c = getchar();
    } else if (c == '*' && previous == '/') {
      while ((c = getchar()) != EOF && !(previous == '*' && c == '/')) {
        previous = c;
      }
      
      c = getchar();      } else {
      putchar(previous);
    }
    previous = c;
  }

  if (previous != EOF) {      putchar(previous);
  }
  return 0;
}

