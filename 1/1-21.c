// copyright
#include <stdio.h>

#define MAXSIZE  1000 /* max line size (for getline) */
#define TAB_SIZE 8    /* number of spaces in a tab */

int getLine(char line[], int size);
void entab(char newLine[], char line[]) {
  int i = 0;
  int ni = 0;
  int from, to;
  while (line[i] != '\0') {
    if (line[i] == ' ') {
      from = i;
      while (line[i] == ' ') {
        ++i;
      }
      to = i;
      /* printf("from %d, to %d\n", from, to); */

      // while tabs fit, add them
      while ((from / TAB_SIZE + 1) * TAB_SIZE <= to) {
        newLine[ni++] = '\t';
        from = (from / TAB_SIZE + 1) * TAB_SIZE;
      }

      while (from + 1 <= to) {
        newLine[ni++] = ' ';
        from = from + 1;
      }
    }

       newLine[ni++] = line[i++];
  }
  newLine[ni++] = '\0';
}

void print(char line[]) {
  int i = 0;
  while (line[i] != '\0') {
    if (line[i] == ' ') {
      printf("S");
    } else if (line[i] == '\t') {
      printf("T");
    } else {
      printf("%c", line[i]);
    }
    ++i;
  }
}

int main() {
  int c;
  char line[MAXSIZE];
  char newLine[MAXSIZE];

  while (getLine(line, MAXSIZE) > 0) {
    entab(newLine, line);
    printf("%s", newLine);
    print(newLine);
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

