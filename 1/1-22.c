// copyright
#include <stdio.h>

#define MAX_LINE 80  /* max number of chars in a line */

#define MAX_BACK 5  // max number of chars to go back looking for a whitespace
//                     when folding the lines

int getLine(char line[], int maxLine);

// from to is [, ) range
void print(char line[]) {
  int from, to;

  from = 0;
  to = 0;
  while (1) {
    to = from;
    while (to - from < MAX_LINE && line[to] != '\n') {
      ++to;
    }

    int i = 0;
    while (i < 5 && to - i > from && line[to - i] != '\n'
           && line[to - i] != ' ')  {
      ++i;
    }

    int dash = 0;
    int space = 0;
    if (line[to - i] == ' ' || line[to - i] == '\n') {
      // + 1 so you don't actually print the space itself,
      // goto: spaceline to see where it's used
      space = 1;
      to = to - i;
    } else {
      dash = 1;

      // print one less chars so there's space for the dash
      if (dash && to > from + 1) {
        --to;
      }
    }

    // print [from, to)
       for (int i = from; i < to; ++i) {
         printf("%c", line[i]);
       }

    if (dash) {
    printf("-");
    }

    printf("\n");

    // end of the big line
    if (line[to] == '\n') {
      break;
    }

    // space-line
    from = to + space;
  }
}


int main() {
  char line[MAX_LINE];

  int len;
  while ((len = getLine(line, 1000)) > 0) {
    print(line);
  }

  return 0;
}

int getLine(char line[], int maxLine) {
  int c;
  int len = 0;
  while (len < maxLine - 1 && (c = getchar()) != EOF && c != '\n') {
    line[len++] = c;
  }

  if (c == '\n') {
    line[len++] = '\n';
  }

  line[len] = '\0';
  return len;
}

