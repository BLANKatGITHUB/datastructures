//This program reverses a given list using stacks
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int stack[MAX];//stack to store data before reversing
int top=-1;//pointer to point at stack
void push(int);//function to push elements in stack
int pop();//function to pop elements from stack
void display(int*,int);
int main()
{
    int list[MAX],size,i;
    printf("Enter the size of array \n");
    scanf("%d",&size);
    
    printf("enter the elements\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&list[i]);
    }

    printf("Your array is ");
    display(list,size);

    for(i=0;i<size;i++)
    {
        push(list[i]);
    }

    for(i=0;i<size;i++)
    {
        list[i]=pop();
    }
    printf("New array is ");
    display(list,size);

}

void push(int val)
{
    if(top==MAX-1)
    {
        printf("Overflow");
        exit(1);
    }
    else
    {
        stack[++top]=val;
    }
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

void display(int* arr,int size)
{
    int i;
    
    for(i=0;i<size;i++)
    {
        printf("%d  ",arr[i]);
    }

    printf("\n");
}