#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node *prev,*next;
}nodes;
 nodes *start=NULL;

 nodes create_ll();
 nodes display();
 nodes insertbef();
 nodes insertaft();
 nodes search();
 nodes insertbeg();
 nodes deletebeg();
 nodes deleteatpoint();

int main()
{   int x;
  
    do
    {   
        printf("1. create a link list \n");
        printf("2. search in link list \n");
        printf("3. insert a node before a data \n");
        printf("4. insert a node after a data\n");
        printf("5. insert a node at first a data\n");
        printf("6. display\n");
        printf(" enter the task to perform like 1,2,3\n");
        printf("7. to delete first element enter 7\n");
        printf("8. to delete specific element enter 8\n");
        printf("to exit enter 0\n");
        scanf("%d",&x);
        
        switch(x)
        {
            case 1: create_ll();
            break;
            case 2: search();
            break;
            case 3: insertbef();
            break;
            case 4: insertaft();
            break;
            case 5: insertbeg();
            break;
            case 6: display();
            break;
            case 7: deletebeg();
            break;
            case 8: deleteatpoint();
            break;
        }
    } while (x!=0);
    return 0;
}
//creating the link lists
nodes create_ll()
{    
    int x;
    nodes *new_node,*ptr;
    new_node=(nodes*)malloc(sizeof(nodes));
    printf("Enter the value\n");
    scanf("%d",&x);
    if(start==NULL)
    {  
     new_node->next=new_node->prev=new_node;
     new_node->data=x;
     start=new_node;
    }
    else
    {ptr=start;
     while(ptr->next!=start)
     ptr=ptr->next;
     ptr->next=new_node;
     new_node->prev=ptr;
     new_node->next=start;
     start->prev=new_node;
     new_node->data=x;
     
  
    }
}
    nodes insertbeg()
    {
     nodes  *new_node=(nodes*)malloc(sizeof(nodes));
     printf("enter the data\n");
     scanf("%d",&new_node->data);
     new_node->next=start;
     new_node->prev=start->prev;
     start->prev=new_node;
     start=new_node;
    }
        nodes insertbef()
        {
            int num;
            nodes *new_node=(nodes*)malloc(sizeof(nodes)),*ptr,*preptr;
            printf("enter the data before which new data is to be placed\n");
            scanf("%d",&num);
            printf("enter the data \n");
            scanf("%d",&new_node->data); 
            ptr=start;
            while(ptr->data!=num)
            {preptr=ptr;
             ptr=ptr->next;}
             preptr->next=new_node;
             new_node->prev=preptr;
             ptr->prev=new_node;
             new_node->next=ptr;
             printf("new node has been placed \n");
        }
         nodes insertaft()
         {  int num;
            nodes *new_node=(nodes*)malloc(sizeof(nodes)),*ptr,*preptr;
            printf("enter the data after which new data is to be placed \n");
            scanf("%d",&num);
            printf("enter the data \n");
            scanf("%d",&new_node->data);
            preptr=start;
            while(preptr->data!=num)
            preptr=preptr->next;
            ptr=preptr->next;
            preptr->next=new_node;
            new_node->prev=preptr;
            new_node->next=ptr;
            ptr->prev=new_node;
         }
          nodes search()
            {
              int num,x=0,y=0;
              nodes *ptr;
              printf("enter number to search \n");
              scanf("%d",&num);
              for(ptr=start;ptr!=NULL;ptr=ptr->next)
              { 
                y++;
                if (ptr->data==num)
                {printf("%d is at position number %d ",num,y);
                x++;
                }
              }
              if(x==0)
              printf("number is not in the list \n");
              }
          
           nodes display()
           { 
            nodes *ptr=start;
            printf("\nthe data on linked list are ");
            while (ptr!=start);
            {
              printf("\t%d",ptr->data);
              ptr=ptr->next;
            } 
            printf("\n");
           }
           nodes deletebeg()
           {
            nodes *ptr;
            ptr=start;
            start=start->next;
            start->prev=ptr->prev;
            ptr->next=NULL;
            free(ptr);
           }
           nodes deleteatpoint()
           {
            nodes *ptr,*preptr,*temp;
            int num;
            ptr=start;
            printf("enter the value to delete");
            scanf("%d",&num);

            while(ptr->data!=num)
           { preptr=ptr;
            ptr=ptr->next;}
            preptr->next=temp=ptr->next;
            temp->prev=preptr;
            ptr->next=NULL;
            free(ptr);


           }