// copyright
#include <stdio.h>

/* strlen: return length of s */
int strlen(char s[]) {
  int i;

  i = 0;
  while (s[i]) {
    ++i;
  }

  return i;
}

int main() {
  char s[100] = "hello" " " "world\0";
  printf("%s: %d\n", s, strlen(s));
  printf("%d\n", '\0');
  printf("%d\n", 0);
  printf("%d\n", '\0' == 0);

  enum boolean {NO, YES};
  return 0;
}
