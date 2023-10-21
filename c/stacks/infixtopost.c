#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#define max 100

char stack[max];
int top = -1;
char pop();
void push(char x);
int priority(char x);
void infixtopostfix(char *infix, char *postfix);

int main() {
  char infix[100], postfix[100];
  printf("Enter the expression");
  fgets(infix, max, stdin);
  infix[strcspn(infix, "\n")] = 0;
  infixtopostfix(infix, postfix);
  puts(postfix);
}

char pop() {
  char val;
  if (top == -1) {
    printf("underflow");
    exit(1);
  } else {
    val = stack[top--];
    return val;
  }
}

void push(char x) {
  if (top == max - 1) {
    printf("overflow");
    exit(1);
  } else {
    stack[++top] = x;

  }
}

int priority(char x)
{
    if (x == '^')
        return 3;
    if (x == '*'|| x == '/')
        return 2;
    if (x == '+'|| x == '-')
        return 1;

    return 0;
}

void infixtopostfix(char *infix, char *postfix) {
  char *p, *i;
  i = infix;
  p = postfix;
  while (*i != '\0') {
    if (isalpha(*i) || isdigit(*i)) {
      *p = *i;
      p++;
      i++;
    } else if (*i == '(') {
      push(*i);
      i++;
    } else if (*i == ')') {
      while ((top != -1) && (stack[top] != '(')) {
        *p = pop();
        p++;

      }
      if (top == -1) {
        printf("invalid statement");
        exit(1);
      }
      pop();
      i++;

    }
    else if (*i=='+'||*i=='*'||*i=='/'||*i=='-'||*i=='^') {
    while((top!=-1) && priority(*i) <= priority(stack[top])) {
        *p=pop();
        p++;
    }
        
    push(*i);
    i++;
}


     else {
      printf("invalid expression");
      exit(1);
    }
  }
  while ((top != -1) && (stack[top] != '(')) {
    *p = pop();
    p++;
  }
  *p = '\0';
}