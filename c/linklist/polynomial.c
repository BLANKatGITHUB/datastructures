#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node {
    int coff, pow;
    struct node *next;
} node;

node* start1 = NULL; // head of first polynomial
node* start2 = NULL; // head of second polynomial
node* start3 = NULL; // head of resultant polynomial
node* start4 = NULL; // head of resultant polynomial

node* create();
void display(node*);
node* add(node*, node*);
node* sub(node*, node*);
node* result(node*, int, int);

int main()
{
    int x;

    do
    {
        printf("\n\n1. Create 1st polynomial");
        printf("\n2. Create 2nd polynomial");
        printf("\n3. Display 1st polynomial");
        printf("\n4. Display 2nd polynomial");
        printf("\n5. Add polynomials");
        printf("\n6. Subtract polynomials");
        printf("\n7. Display result");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            start1 = create();
            break;
        case 2:
            start2 = create();
            break;
        case 3:
            display(start1);
            break;
        case 4:
            display(start2);
            break;
        case 5:
            start3 = add(start1, start2);
            break;
        case 6:
            start4 = sub(start1, start2);
            break;
        case 7:
            printf("\n1st polynomial: ");
            display(start1);
            printf("\n2nd polynomial: ");
            display(start2);
            printf("\nAddition: ");
            display(start3);
            printf("\nSubtraction: ");
            display(start4);
            break;
        case 8:
            printf("\nExiting...");
            break;
        default:
            printf("\nInvalid choice!");
            break;
        }
    } while (x!=8);
    
}

node* create()
{
    node *start=NULL, *new_node, *ptr;
    int i,n;

    printf("\nEnter the number of terms: ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        new_node = (node*)malloc(sizeof(node));
        printf("\nEnter the coefficient and power of x: ");
        scanf("%d%d", &new_node->coff, &new_node->pow);
        new_node->next = NULL;

        if(start == NULL)
        {
            start = new_node;
        }
        else
        {
            ptr = start;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
        }
    }
    return start;
}

void display(node* start)
{
    node *ptr=start;
    printf("The polynomial is: ");
    while(ptr!=NULL)
    {
        printf("%dx^%d", ptr->coff, ptr->pow);
        ptr = ptr->next;
        if(ptr!=NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

node* result(node* start, int coff, int pow)
{
    node *new_node, *ptr;
    new_node = (node*)malloc(sizeof(node));
    new_node->coff = coff;
    new_node->pow = pow;
    new_node->next = NULL;

    if(start == NULL)
    {
        start = new_node;
    }
    else
    {
        ptr = start;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        }
        return start;
        }

        node* add(node *start1, node *start2)
        {
            node *start=NULL;
            node *ptr1=start1, *ptr2=start2;

            if(ptr1==NULL||ptr2==NULL)
            {
                printf("\nAddition not possible!");
                return NULL;
            }
            else{
                while(ptr1 != NULL && ptr2 != NULL)
                {
                    if(ptr1->pow == ptr2->pow)
                    {
                        start=result(start, ptr1->coff + ptr2->coff, ptr1->pow);
                        ptr1=ptr1->next;
                        ptr2=ptr2->next;
                    }
                    else if(ptr1->pow > ptr2->pow)
                    {
                        start=result(start,ptr1->coff,ptr1->pow);
                        ptr1=ptr1->next;
                    }
                   else  if(ptr1->pow < ptr2->pow)
                    {
                        start=result(start,ptr2->coff,ptr2->pow);
                        ptr2=ptr2->next;
                    }
                }
                if(ptr1 != NULL || ptr2 != NULL)
                {
                    while(ptr1 != NULL)
                    {
                        start=result(start,ptr1->coff,ptr1->pow);
                        ptr1=ptr1->next;
                    }
                    while(ptr2 != NULL)
                    {
                        start=result(start,ptr2->coff,ptr2->pow);
                        ptr2=ptr2->next;
                    }
                }
         
            }
            return start;

        }

        node *sub(node *start1, node *start2)
        {
            node *start=NULL;
            node *ptr1=start1, *ptr2=start2;

            if(ptr1==NULL||ptr2==NULL)
            {
                printf("\nSubtraction not possible!");
                return NULL;
            }
            else{
                while(ptr1 != NULL && ptr2 != NULL)
                {
                    if(ptr1->pow == ptr2->pow)
                    {
                        start=result(start, ptr1->coff - ptr2->coff, ptr1->pow);
                        ptr1=ptr1->next;
                        ptr2=ptr2->next;
                    }
                   else if(ptr1->pow > ptr2->pow)
                    {
                        start=result(start,ptr1->coff,ptr1->pow);
                        ptr1=ptr1->next;
                    }
                   else if(ptr1->pow < ptr2->pow)
                    {
                        start=result(start,ptr2->coff,ptr2->pow);
                        ptr2=ptr2->next;
                    }
                }
                if(ptr1 != NULL || ptr2 != NULL)
                {
                    while(ptr1 != NULL)
                    {
                        start=result(start,ptr1->coff,ptr1->pow);
                        ptr1=ptr1->next;
                    }
                    while(ptr2 != NULL)
                    {
                        start=result(start,ptr2->coff,ptr2->pow);
                        ptr2=ptr2->next;
                    }
                }
         
            }
            return start;

        }
