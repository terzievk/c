// copyright
#include <stdio.h>

#define IN  1
#define OUT 0
#define MAX_WORD_SIZE 10

int main() {
  int c, l, state;
  int wLengths[MAX_WORD_SIZE];

  int i;
  for (i = 0; i < MAX_WORD_SIZE; ++i) {
    wLengths[i] = 0;
  }

  state = OUT;
  l = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) {
        state = OUT;
        ++wLengths[l];
        l = 0;
      }
    } else {
      ++l;
      if (state == OUT) {
        state = IN;
      }
    }
  }

  int max = 0;
  for (i = 0; i < MAX_WORD_SIZE; ++i) {
    if (wLengths[i] > max) {
      max = wLengths[i];
    }
  }

  for (i = 0; i < max; ++i) {
    int j;
    for (j = 0; j < MAX_WORD_SIZE; ++j) {
      if (wLengths[j] >= max - i) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }


  for (i = 0; i < MAX_WORD_SIZE; ++i) {
    printf("%d", i);
  }



  return 0;
}
