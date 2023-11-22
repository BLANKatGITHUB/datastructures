#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *front=NULL,*rear=NULL;

void insert(int);
int delete();
void display();

int main(){
    int choice,item;
    while(1){
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                item = delete();
                if(item == -1)
                    printf("Queue is empty\n");
                else
                    printf("Deleted element is %d\n", item);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong choice\n");
        }
    }
}

void insert(int item){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=item;

    if(front==NULL){
        front=rear=newnode;
        newnode->next=NULL;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        newnode->next=NULL;
    }

}

int delete(){
    int item;
    node *temp;
    if(front==NULL)return -1;
    else{
        item=front->data;
        temp=front->next;
        free(front);
        front=temp;
        return item;
    }
}

void display(){
    node *temp;
    if(front==NULL)printf("Queue is empty\n");
    else{
        temp=front;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
