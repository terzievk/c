// copyright
#include <stdio.h>

#define MAXSIZE  1000 /* max line size (for getline) */
#define TAB_SIZE 8    /* number of spaces in a tab */

int getLine(char line[], int size);
void detab(char newLine[], char line[]) {
  int count = 0;
  int len = 0;
  while (line[count] != '\0') {
    if (line[count] == '\t') {
      do {
        newLine[len++] = ' ';
      } while (len % 8);
    } else {
      newLine[len++] = line[count];
    }
    ++count;
  }

  newLine[len++] = '\0';
}

int main() {
  int c;
  char line[MAXSIZE];
  char newLine[MAXSIZE];

  while (getLine(line, MAXSIZE) > 0) {
    detab(newLine, line);
    printf("%s", newLine);
  }
  return 0;
}

int getLine(char line[], int size) {
  int c;
  int count = 0;

  while (count < size - 1 && (c = getchar()) != EOF && c != '\n') {
    line[count++] = c;
  }

  if (c == '\n') {
    line[count++] = '\n';
  }

  line[count] = '\0';

  return count;
}

