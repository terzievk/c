// copyright
#include <stdio.h>

/*
  1-23-result.c is direct result from:
  ```
  ./f < 1-23.c > 1-23-result.c
  ```
  and it compiles and can be called on itself successfully

  Known issues:
  - assume no comments in quotes 
  - mess up mixed code + comment lines(deletes the newline) 
  - leaves blank lines when deleting multiline comments
*/
int /*mid comment*/main() {
  int c;
  int previous = getchar();

  while ((c = getchar()) != EOF) {
    if (c == '/' && previous == '/') {
      while ((c = getchar()) != EOF && c != '\n') {
      }
      // if c == '\n' (once EOF, always EOF)
      c = getchar();
    } else if (c == '*' && previous == '/') {
      while ((c = getchar()) != EOF && !(previous == '*' && c == '/')) {
        previous = c;
      }
      /* previous == * && c == / */
      c = getchar();  // for the last / of /* ... */
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

