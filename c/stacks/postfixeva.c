#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define max 100
int top=-1;
void push(float val);
float pop();
float eval(char* );
float stack[max];
int main()
{   float result;
    char postfix[max];
    printf("Enter the postfix expression");
    fgets(postfix,max,stdin);
    if(postfix[strlen(postfix)-1]=='\n')
    postfix[strlen(postfix)-1]='\0';
    result=eval(postfix);
    printf("The result of the postfix expression is %f ",result);

}
void push(float val)
{
    if(top==max-1)
    {printf("overflow");
    exit(1);}
    else 
    stack[++top]=val;
}
float pop()
{
    if(top==-1)
    {
    printf("Underflow");
    exit(1);}
    else
    return stack[top--];
}
float eval(char* p)
{   float val;
    while(*p!='\0')
    {
        if(isdigit(*p))
        {
        push((float)(*p-'0'));
        p++;}
        else
        {
            float op2=pop(),op1=pop();
            switch(*p)
            {
                case '+':
                push(op1+op2);
                p++;
                break;
                case '-':
                push(op1-op2);
                p++;
                break;
                case '/':
                push(op1/op2);
                p++;
                break;
                case '%':
                push((int)op1%(int)op2);
                p++;
                break;
                case '*':
                push(op1*op2);
                p++;
                break;
                case '^':
                push((int)op1^(int)op2);
                p++;
                break;

                default:
                printf("invalid statement");
                exit(1);
                break;

            }

        }
    }
    val=pop();
    return val;
}

