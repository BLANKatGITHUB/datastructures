#include<stdlib.h>
#include<stdio.h>
#define MAX 5

int queue[MAX];
int front =-1, rear =-1;

void insertrear(int);
void insertfront(int);
int deletefront(); 
int deleterear();
void display();
void inputrestricted();
void outputrestricted();

int main(){
    int choice, item;
    while(1){
        printf("\n1. Input restricted\n2. Output restricted\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                inputrestricted();
                break;
            case 2:
                outputrestricted();
                break;
            case 3:
                exit(1);
            default:
                printf("Wrong choice\n");
        }
    }
}

void inputrestricted(){
    int choice, item;
    while(1){
        printf("\n1. Insert rear\n2. Delete front\n3. Delete rear\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                insertrear(item);
                break;
            case 2:
                item = deletefront();
                if(item == -1)
                    printf("Queue is empty\n");
                else
                    printf("Deleted element is %d\n", item);
                break;
            case 3:
                item = deleterear();
                if(item == -1)
                    printf("Queue is empty\n");
                else
                    printf("Deleted element is %d\n", item);
                break;
            case 4:
                display();
                break;
            case 5:
                return;
            default:
                printf("Wrong choice\n");
        }
    }
}

void outputrestricted(){
    int choice, item;
    while(1){
        printf("\n1. Insert rear\n2. Insert front\n3. Delete front\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                insertrear(item);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                insertfront(item);
                break;
            case 3:
                item = deletefront();
                if(item == -1)
                    printf("Queue is empty\n");
                else
                    printf("Deleted element is %d\n", item);
                break;
            case 4:
                display();
                break;
            case 5:
                return;
            default:
                printf("Wrong choice\n");
        }
    }
}

void insertrear(int item){
    if(((front == 0 )&&(rear==MAX-1))||(front==rear+1))printf("overflow\n");
    else if(front==-1){
        front=rear=0;
        queue[front]=item;
    }
    else if (rear==MAX-1){
        rear=0;
        queue[rear]=item;
    }
    else{
        queue[++rear]=item;
    }
}

void insertfront(int item){
    if(((front == 0 )&&(rear==MAX-1))||(front==rear+1))printf("overflow\n");
    else if(front==-1){
        front=rear=0;
        queue[front]=item;
    }
    else if (front==0){
        front=MAX-1;
        queue[front]=item;
    }
    else{
        queue[--front]=item;
    }
}
int deletefront(){
    int item;
    if(front==-1)return -1;
    else if(front==rear){
        item=queue[front];
        front=rear=-1;
    }
    else if(front==MAX-1){
        item=queue[front];
        front=0;
    }
    else{
        item=queue[front++];
    }
    return item;
}

int deleterear(){
    int item;
    if(front==-1)return -1;
    else if(front==rear){
        item=queue[front];
        front=rear=-1;
    }
    else if(rear==0){
        item=queue[rear];
        rear=MAX-1;
    }
    else{
        item=queue[rear--];
    }
    return item;
}

void display(){
    int i;
    if(front==-1)printf("empty\n");
    else if(front<=rear){
        for(i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
    else{
        for(i=front;i<MAX;i++){
            printf("%d ",queue[i]);
        }
        for(i=0;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
}