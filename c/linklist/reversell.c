#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *start=NULL;

void createlist();
void display();
void reversell();
int main(){
    int x;
    do
    {
        printf("1. create a link list \n");
        printf("2. display\n");
        printf("3. reverse the link list\n");
        printf("to exit enter 0\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1: createlist();
            break;
            case 2: display();
            break;
            case 3: reversell();
            break;
            default: printf("enter a valid choice\n");
                    return 0;
        }
    } while (x!=0);
    return 0;
}

void createlist(){
    int i,n;
    node *newnode,*ptr;
    printf("enter the number of nodes\n");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        newnode=(node*)malloc(sizeof(node));
        printf("enter the data of node %d\n",i+1);
        scanf("%d",&newnode->data);
        if(start== NULL){
            start=newnode;
            newnode->next=NULL;
        }
        else{
            ptr=start;while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->next=NULL;
        }
    }
    return;
}

void reversell(){
    node *curr,*prev;
    if(start==NULL){
        printf("create a link list first\n");
        return;
    }
    prev=start;
    start=start->next;
    curr=start;
    prev->next=NULL;
    start=start->next;
    curr->next=prev;
    while(start!=NULL){
        prev=curr;
        curr=start;
        start=start->next;
        curr->next=prev;
    }
    start=curr;
    return;
}

void display(){
    node *ptr=start;
    printf("The linked list is\n");
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    return;
}
