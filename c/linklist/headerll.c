#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node *next;
}nodes;
nodes* start=NULL;
void create();
void display();

int main()
{
    int x;
    do
    {
        printf("1. create a link list \n");
        printf("2. display\n");
        printf(" enter the task to perform like 1,2,3\n");
        printf("to exit enter 0\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1: create();
            break;
            case 2: display();
            break;
        }
    } while (x!=0);
    return 0;
}

void create()
{
    nodes *newnode,*temp;
    newnode=(nodes*)malloc(sizeof(nodes));
    printf("enter the data\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(start==NULL)
    {   
        start=(nodes*)malloc(sizeof(nodes));
        start->next=newnode;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void display()
{
    nodes *temp;
    temp=start->next;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
