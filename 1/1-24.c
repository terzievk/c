// copyright
#include <stdio.h>

/*
  "rudimentary syntax error" check could mean anything from lexer to compiler
  so I'll assume no parentheses, brackets or braces in quotes, escape sequences
  and or comments

  Solution is based on basic rough stack

```
./f < 1-24.c --- fails

./f < 1-01.c works
```
*/
#define MAX 1000

int stack[MAX];
int size = 0;
int top() {
  if (!size) {
    printf("called top on empty stack!\n");
    return 1;
  }
  return stack[size - 1];
}
void pop() {
  if (size > 0) {
    --size;
  }
}

void push(int c) {
  stack[size++] = c;
}
int empty() {
  return size == 0;
}

int main() {
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '(' || c == '[' || c == '{') {
      push(c);
    } else if (c == ')') {
      if (top() == '(') {
        pop();
      } else {
        printf("Error\n");
        return 1;
      }
    } else if (c == ']') {
      if (top() == '[') {
        pop();
      } else {
        printf("Error\n");
        return 1;
      }
    } else if (c == '}') {
      if (top() == '{') {
        pop();
      } else {
        printf("Error\n");
        return 1;
      }
    }
    putchar(c);
  }

  if (empty()) {
    printf("All good!\n");
  }

  return 0;
}
