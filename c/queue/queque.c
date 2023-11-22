#include<stdlib.h>
#include<stdio.h>
#define MAX 5

int queue[MAX];
void insert(int);
int delete();
void display();
void display();

int front =-1, rear =-1;

void main()
{
    int choice, item;
    while(1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
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
    if(rear==MAX-1)printf("overflow\n");
    else if(front==-1){
        front=rear=0;
        queue[front]=item;
    }
    else{
        queue[++rear]=item;
    }

}

int delete(){
    int item;
    if(front==-1)return -1;
    else if(front==rear){
        item=queue[front];
        front=rear=-1;
    }
    else{
        item=queue[front++];
    }
    return item;
}

void display(){
    int i;
    if(front==-1)printf("Queue is empty\n");
    else{
        for(i=front;i<=rear;i++){
            printf("%d\t",queue[i]);
        }
    }
}