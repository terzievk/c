// copyright
#include <stdio.h>

int main() {
  int nb, nt, nl, c;
  nb = 0;
  nt = 0;
  nl = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++nb;
    }
    if (c == '\t') {
      ++nt;
    }
    if (c == '\n') {
      ++nl;
    }
  }
  printf("%d\n", nb);
  printf("%d\n", nt);
  printf("%d\n", nl);
  return 0;
}
