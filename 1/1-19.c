// copyright
#include <stdio.h>

#define MAXLINE   1000   /* maximum input line size */

int getLine(char line[], int maxLine);
void reverse(char line[], int len);

int main() {
  int len;   /* current line length */
  char line[MAXLINE];     /* current input line */

  while ((len = getLine(line, MAXLINE)) > 0) {
       reverse(line, len);
    printf("%s", line);
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

/* reverse: get line s and reverse it */
void reverse(char s[], int len) {
  --len;  // leave '\n' at the end
  for (int i = 0; i <= len / 2; ++i) {
    int temp = s[i];
    s[i] = s[len - i - 1];
    s[len - i - 1] = temp;
  }
}
