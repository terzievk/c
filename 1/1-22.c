// copyright
#include <stdio.h>

#define MAX_LINE 8  /* max number of chars in a line */

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
    to = to - i;

    printf("from: %d, to: %d\n", from, to);
    // print [from, to)
    for (int i = from; i < to; ++i) {
      printf("%c", line[i]);
    }
    printf("\n");

    if (line[to] == '\n') {
      break;
    }
    from = to;
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

