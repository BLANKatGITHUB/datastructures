#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20
void push(char);
char pop();
void checker(char *);
char stack[max];
int top=-1,flag=0;

int main()
{
  char exp[max];
  printf("Enter the expression");
  gets(exp);
  checker(exp);
}
void push(char a)
{ 
 if(top==max-1)
 printf("overflow");
 else
 stack[++top]=a;
}
char pop()
{
    if(top==-1)
    printf("underflow");
    else
    return stack[top--];
}

void checker(char *exp)
{   
    int i=0;
    char temp;
    
    for(i;exp[i]!='\0';i++)
    {if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
    push(exp[i]);
    if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
       if (top==-1)
       printf("invalid exp");
       else
       {temp=pop();
        if(temp=='('&&(exp[i]=='}'||exp[i]==']'))
        flag=1;
        if(temp=='{'&&(exp[i]==')'||exp[i]==']'))
        flag=1;
        if(temp=='['&&(exp[i]=='}'||exp[i]==')'))
        flag=1;
       }}
if(top>-1)
flag=1;
if(flag==1)
printf("invalid exp");
if(flag==0)
printf("valid exp");
      

}