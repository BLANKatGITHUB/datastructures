#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

char pop() {
  if (top == -1) {
    printf("Underflow error: Stack is empty\n");
    exit(1);
  }
  return stack[top--];
}

void push(char x) {
  if (top == MAX - 1) {
    printf("Overflow error: Stack is full\n");
    exit(1);
  }
  stack[++top] = x;
}

int priority(char x) {
  switch (x) {
    case '^':
      return 3;
    case '*':
    case '/':
      return 2;
    case '+':
    case '-':
      return 1;
    default:
      return 0;
  }
}

void reverse(char *str) {
  int l = strlen(str);
  for (int i = 0; i <= l / 2; i++) {
    if(str[i] == '(') str[i] = ')';
    else if(str[i] == ')') str[i] = '(';
    if(str[l - i - 1] == '(') str[l - i - 1] = ')';
    else if(str[l - i - 1] == ')') str[l - i - 1] = '(';
    char temp = str[i];
    str[i] = str[l - i - 1];
    str[l - i - 1] = temp;
  }
}

char* infixtopostfix(char *infix) {
  int l = strlen(infix);
  char *postfix = malloc(l + 1);
  if (!postfix) {
    printf("Memory allocation error\n");
    exit(1);
  }
  char *p = postfix;
  for (char *i = infix; *i != '\0'; i++) {
    if (isalpha(*i) || isdigit(*i)) {
      *p++ = *i;
    } else if (*i == '(') {
      push(*i);
    } else if (*i == ')') {
      while (top != -1 && stack[top] != '(') {
        *p++ = pop();
      }
      if (top == -1) {
        printf("Invalid expression error: Mismatched parentheses\n");
        exit(1);
      }
      pop();
    } else if (*i == '+' || *i == '-' || *i == '*' || *i == '/' || *i == '^') {
      while (top != -1 && priority(*i) <= priority(stack[top])) {
        *p++ = pop();
      }
      push(*i);
    } else {
      printf("Invalid expression error: Unknown character '%c'\n", *i);
      exit(1);
    }
  }
  while (top != -1 && stack[top] != '(') {
    *p++ = pop();
  }
  *p = '\0';
  return postfix;
}

void infixtoprefix(char *infix, char *prefix) {
  int l = strlen(infix);
  char *postfix = infixtopostfix(infix);
  reverse(postfix);
  strcpy(prefix, postfix);
  free(postfix);
}

int main() {
  char infix[MAX], prefix[MAX];
  printf("Enter the expression: ");
  fgets(infix, MAX, stdin);
  infix[strcspn(infix, "\n")] = '\0';
  reverse(infix);
  infixtoprefix(infix, prefix);
  printf("Prefix expression: %s\n", prefix);
  return 0;
}