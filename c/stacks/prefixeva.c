#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define max 100

int stack[max];
int top = -1;

void push(int item);
int pop();
void prefixeva(char *);
int isoperand(char);

int main()
{
    char prefix[max];
    printf("Enter the prefix expression\n");
    fgets(prefix, max, stdin);
    prefix[strcspn(prefix, "\n")]='\0';
    prefixeva(prefix);
    return 0;
}

void push(int item)
{
    if(top==max-1)
    {
        printf("Stack Overflow\n");
        
    }
    else{
        stack[++top]=item;
     
    }
}

int pop(){
    int item;
    if(top==-1){
        printf("Stack Underflow\n");
        return 0;
    }
    else{
        item=stack[top--];
        return item;
    }
}

void prefixeva(char *prefix){
    int i,l,item;
    l=strlen(prefix);
    for(i=l-1;i>=0;i--){
        if(isdigit(prefix[i])){
            push(prefix[i]-'0');
        }
        else if(prefix[i]=='+'||prefix[i]=='-'||prefix[i]=='*'||prefix[i]=='/'||prefix[i]=='^'){
            int a,b;
            b=pop();
            a=pop();
            switch(prefix[i]){
                case '+':
                    push(a+b);
                    break;
                case '-':
                    push(a-b);
                    break;
                case '*':
                    push(a*b);
                    break;
                case '/':
                    push(a/b);
                    break;
                case '^':
                    push(pow(a,b));
                    break;
            }
        }
        else{
            printf("Invalid Expression\n");
        }
    }
    item=pop();
    if(top==-1){
        printf("Result is %d\n",item);
    }
    else{
        printf("Invalid Expression\n");
        return;
    }
}