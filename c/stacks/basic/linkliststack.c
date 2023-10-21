#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    struct stack* next;
    int val;
}stack;

stack* top=NULL;
stack* getnode();
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

stack* getnode()
{
    stack* node=(stack*)malloc(sizeof(stack));
    return node;
}

int pop()
{   
    stack* ptr;
    int val;
    if(top==NULL)
    {
        printf("Underflow");
        exit(1);
    }
    else
    {
        ptr=top;
        top=top->next;
        val=ptr->val;
        free(ptr);
        return val;

    }
}


void push(int val)
{
    stack* ptr;
    ptr=getnode();
    ptr->val=val;
    if(top==NULL)
    {
        top=ptr;
        top->next=NULL;
    }
    else
    {
        ptr->next=top;
        top=ptr;
    }
}

int peek()
{
    if(top==NULL)
    {
        printf("There are no elements\n");
    }
    else
    {
        printf("The topmost element is %d\n",top->val);
    }
} 