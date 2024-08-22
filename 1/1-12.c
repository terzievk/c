// copyright
#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

int main() {
  int c , state;

  state = OUT;
  while ((c = getchar()) != EOF) {
    if (state == IN && c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      putchar('\n');
    } else if (state == IN) {
      putchar(c);
    } else if (c != ' ' && c != '\n' && c != '\t') {
      putchar(c);
      state = IN;
    }
  }

  return 0;
}
