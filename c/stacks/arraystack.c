#include<stdio.h>
#include<stdlib.h>
#define max 10
int stack[10];//creates a stack
int top=-1;//pointer top which points to topmost element of stack
int pop();//function to perform push operation
void push(int );//function to perform pop
int peek();//returns the topmost element of stack
int main()
{   int val,option;
    do
    {
        printf("1. Enter 1 to push a value\n");
        printf("2. Enter 2 to pop a value\n");
        printf("3. Enter 3 to peek the value\n");
        printf("4. Enter 4 to exit\n");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                    printf("Enter the value\n");
                    scanf("%d",&val);
                    push(val);
                    break;
            case 2: 
                    val=pop();
                    printf("The value is %d\n",val);
                    break;
            case 3:
                    peek();
                    break;

            default:
                    printf("Invalid statement\n");
                    break;
        }
        
    } while (option!=0);
    
}
int pop()
{
    if(top==-1)
    {
        printf("Underflow");
        exit(1);
    }
    else
    {
        return stack[top--];
    }
}

void push(int val)
{
    if(top==max-1)
    {
        printf("Overflow");
        exit(1);
    }

    else
    {
        stack[++top]=val;
    }
}

int peek()
{
    if(top==-1)
    {
        printf("There are no elements\n");
    }
    else
    {
        printf("The topmost element is %d\n",stack[top]);
    }
}