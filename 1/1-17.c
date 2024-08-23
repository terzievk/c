// copyright
#include <stdio.h>

#define MAXLINE   1000   /* maximum input line size */
#define THRESHOLD 80     /* minimum threshold to print a line */

int getLine(char line[], int maxLine);

int main() {
  int len;   /* current line length */
  char line[MAXLINE];     /* current input line */

  while ((len = getLine(line, MAXLINE)) > 0) {
    if (len > THRESHOLD) {
      printf("%s", line);
    }
  }

  return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}
