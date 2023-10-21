#include<stdio.h>
#include<stdlib.h>
#define max 10
int stack[20];//creates a stack
int topA=-1;//pointer top which points to topmost element of stack A
int topB=max;//pointer top which points to topmost element of stack B
int popA();//function to perform push operation on stack A
int popB();//function to perform push operation on stack B
void pushA(int );//function to perform pop on stack A
void pushB(int );//function to perform pop on stack A
void display();//display both stacks
int main()
{   int val,option;
    char name;
    do
    {
        printf("1. Enter 1 to push a value\n");
        printf("2. Enter 2 to pop a value\n");
        printf("3. Enter 3 to view stack\n");
        printf("4. Enter 0 to exit\n");
        scanf("%d",&option);

        switch(option)
        {
            case 1: 
                    printf("\nEnter stack name to make change in A or B");
                    scanf(" %c",&name);
                    if(name=='A')
                    {
                        printf("Enter the value\n");
                        scanf("%d",&val);
                        pushA(val);
                        break;

                    }
                    if(name=='B')
                    {
                        printf("Enter the value\n");
                        scanf("%d",&val);
                        pushB(val);
                        break;
                    }
                    else
                    {
                        printf("invalid statement");
                        break;
                    }
            case 2: 
                    printf("Enter stack name to make change in A or B");
                    scanf(" %c",&name);
                    if(name=='A')
                    {
                    val=popA();
                    printf("The value  is %d\n",val);
                    break;
                    }
                    if(name=='B')
                    {
                    val=popB();
                    printf("The value  is %d\n",val);
                    break;
                    }
                    else
                    {
                        printf("invalid statement");
                        break;
                    }
            case 3:
                    display();
                    break;
            default:
                    printf("Invalid statement\n");
                    break;
        }
        
    } while (option!=0);
    
}
int popA()
{
    if(topA==-1)
    {
        printf("Underflow");
        exit(1);
    }
    else
    {
        return stack[topA--];
    }
}
int popB()
{
    if(topB==max)
    {
        printf("Underflow");
        exit(1);
    }
    else
    {
        return stack[topB--];
    }
}

void pushA(int val)
{
    if(topA==topB-1)
    {
        printf("Overflow");
        exit(1);
    }

    else
    {
        stack[++topA]=val;
    }
}
void pushB(int val)
{
    if(topB==topA+1)
    {
        printf("Overflow");
        exit(1);
    }

    else
    {
        stack[--topB]=val;
    }
}

void display()
{   int i;
    printf("Stack A is ");
    for(i=topA;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\nStack b is ");
    for(i=topB;i<max;i++)
    {
        printf("%d ",stack[i]);
    }


}