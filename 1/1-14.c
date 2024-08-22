// copyright
#include <stdio.h>

#define IN  1
#define OUT 0
#define ASCII_SIZE 128

int main() {
  int c, l, state;
  int wLengths[ASCII_SIZE];

  int i;
  for (i = 0; i < ASCII_SIZE; ++i) {
    wLengths[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    ++wLengths[c];
  }

  int max = 0;
  for (i = 0; i < ASCII_SIZE; ++i) {
    if (wLengths[i] > max) {
      max = wLengths[i];
    }
  }

  for (i = 0; i < max; ++i) {
    int j;
    for (j = 0; j < ASCII_SIZE; ++j) {
      if (wLengths[j] >= max - i) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }


  for (i = 0; i < ASCII_SIZE; ++i) {
    printf("%c", i);
  }

  return 0;
}
