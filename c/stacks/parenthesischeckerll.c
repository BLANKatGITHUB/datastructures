#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20
void push(char);
char pop();
void checker(char *);
int flag=0;
typedef struct stack
{
    struct stack* next;
    char data;
}stack;
stack* top=NULL;


int main()
{
  char exp[max];
  printf("Enter the expression");
  fgets(exp,max,stdin);
  checker(exp);
}
void push(char a)
{ 
stack* newnode;
newnode=(stack*)malloc(sizeof(stack));
newnode->data=a;
if(top==NULL)
{
    newnode->next=NULL;
    top=newnode;
}
else
{
 newnode->next=top;
 top=newnode;
}
}

char pop()
{   char temp;
    stack* ptr;
    if(top==NULL)
    printf("underflow");
    else
    {
     temp=top->data;
     ptr=top;
     top=top->next;
     free(ptr);
     return temp;
    }
}

void checker(char *exp)
{   
    int i=0;
    char temp;
    
    for(i;exp[i]!='\0';i++)
    {if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
    push(exp[i]);
    else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
       if (top==NULL)
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
if(top!=NULL)
flag=1;
if(flag==1)
printf("invalid exp");
if(flag==0)
printf("valid exp");
      

}