#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>

typedef struct node{
    int data;
    struct node *next;
}node;
node *start=NULL;

void createlist();
void display();
node* reversell(node *);
node *midll(node *);
bool paladindromecheck(node *);
int main(){
    int x;
    do
    {
        printf("1. create a link list \n");
        printf("2. display\n");
        printf("3. check if the link list is paladindrome\n");
        printf("to exit enter 0\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1: createlist();
            break;
            case 2: display();
            break;
            case 3: if(paladindromecheck(start)){
                        printf("the link list is paladindrome\n");
                    }
                    else{
                        printf("the link list is not paladindrome\n");
                    }
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
            ptr=start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->next=NULL;
        }
    }
}

void display(){
    node *ptr;
    ptr=start;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

node *reversell(node *start){
    node *ahead,*prev=NULL;
        while(start!=NULL){
            ahead=start->next;
            start->next=prev;
            prev=start;
            start=ahead;
        }
        start=prev;
    return start;
}

node *midll(node *start){
    node *slow,*fast;
    slow=fast=start;

        /*
        this code will find the first middle element in case of even number of nodes
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }*/                        
        while(fast!=NULL && fast->next!=NULL){//this find second code will change accordingly
            slow=slow->next;
            fast=fast->next->next;
            /*you can also find the middle terms by traversing the link list and counting the number of nodes
            then dividing it by 2*/
        }
        return slow;
    }

bool paladindromecheck(node *start){
    node *mid,*start2,*ptr,*ptr2;
    if(start==NULL||start->next==NULL){
        return true;
    }

    else{
        mid=midll(start);
        start2=reversell(mid);
        ptr=start;
        ptr2=start2;
        while(ptr2!=NULL){
            if(ptr->data!=ptr2->data){
                return false;
            }
            ptr=ptr->next;
            ptr2=ptr2->next;
        }
        reversell(start2);
        return true;
    }

}
    
