// copyright
#include <stdio.h>

#define MAXLINE  10   /* maximum input line size */

int getLine(char line[], int maxLine);
void copy(char to[], char from[]);

/* print longest input line */
int main() {
  int len;   /* current line length */
  int max;   /* maximum length seen so far */
  char line[MAXLINE];     /* current input line */
  char tempLine[MAXLINE]; /* temp to pass to getline */
  char longest[MAXLINE];  /* longest line saved here */

  max = 0;
  while ((len = getLine(line, MAXLINE)) > 0) {
    int tempLen = len;
    // maxline - 2 is the last symbol before \0
    while (len == (MAXLINE - 1) && line[MAXLINE-2] != '\n') {
      len = getLine(tempLine, MAXLINE);
      tempLen += len;
    }
    if (tempLen > max) {
      max = tempLen;
      copy(longest, line);
    }
  }

  if (max > 0) {
    printf("longest(%d) starting with: %s", max, longest);
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

/* copy: copy `from` into `to`; assume to is a big enough */
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
