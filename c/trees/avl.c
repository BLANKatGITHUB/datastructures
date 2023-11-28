#include<stdlib.h>
#include<stdio.h>

typedef struct node{
    int data,height;
    struct node *right,*left;
}node;

node* insert(node* root,int data);
node* delete(node* root,int data);
int height(node* root);
int internalnodes(node* root);
int externalnodes(node* root);
node* min(node* root);
node* max(node* root);
int balancenum(node* root);
int totalnodes(node* root);
void inorder(node* root);
void deletetree(node* root);
node* mirror(node* root);
node* search(node* root,int data);
node* rotateleft(node* y);
node* rotateright(node* y);

int main(){
    node* root=NULL;
    int choice,data;
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Height\n5.Internal Nodes\n6.External Nodes\n7.Total Nodes\n8.Inorder\n9.Mirror\n10.Delete Tree\n11.Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the data: ");
                scanf("%d",&data);
                root=insert(root,data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d",&data);
                root=delete(root,data);
                break;
            case 3:
                printf("Enter the data: ");
                scanf("%d",&data);
                root=search(root,data);
                if(root==NULL){
                    printf("Data not found\n");
                }
                else{
                    printf("Data found\n");
                }
                break;
            case 4:
                printf("Height of the tree is %d\n",height(root));
                break;
            case 5:
                printf("Number of internal nodes is %d\n",internalnodes(root));
                break;
            case 6:
                printf("Number of external nodes is %d\n",externalnodes(root));
                break;
            case 7:
                printf("Total number of nodes is %d\n",totalnodes(root));
                break;
            case 8:
                inorder(root);
                break;
            case 9:
                root=mirror(root);
                break;
            case 10:
                deletetree(root);
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

node* rotateleft(node* y){
    node* x=y->right;
    y->right=x->left;
    x->left=y;
    return x;
}

node* rotateright(node* y){
    node* x = y->left;
    y->left=x->right;
    x->right=y;
    return x;
}

int balancenum(node* root){
    if(root == NULL)return 0;
    else return height(root->left)-height(root->right);
}

int height(node* root){
    if(root == NULL)return 0;
    else{
        int left = height(root->left);
        int right = height(root->right);
        if(left>right)return left+1;
        else return right+1;
    }
}

node* insert(node* root,int data){
    if(root == NULL){
        root=(node*)malloc(sizeof(node));
        root->left=root->right=NULL;
        root->data=data;
        root->height=1;
        return root;
    }
    else if(data<root->data) root->left=insert(root->left,data);
    else if(data>root->data) root->right=insert(root->right,data);

    int balance = balancenum(root);

    if(balance>1 && data<root->left->data){
        root = rotateright(root);
        root->height=height(root);
        return root;
    }
    if(balance>1 && data>root->left->data){
        root->left = rotateleft(root->left);
        root=rotateright(root);
        root->height=height(root);
        return root;
    }
    if(balance<-1 && data>root->right->data){
        root = rotateleft(root);
        root->height=height(root);
        return root;
    }
    if(balance<-1 && data<root->right->data){
        root->right = rotateright(root);
        root=rotateleft(root);
        root->height=height(root);
        return root;
    }
    return root;
}

node* delete(node* root, int data){
    if(root == NULL)return root;
    if(data < root->data)root->left=delete(root->left,data);
    else if(data > root->data)root->right=delete(root->right,data);
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        else if(root->left == NULL){
            node* temp=root;
            root=root->right;
            free(temp);
            return root;
        }
        else if(root->right == NULL){
            node* temp=root;
            root=root->left;
            free(temp);
            return root;
        }
        else{
            node* temp=min(root->right);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
    }
    int balance = balancenum(root);
    if(balance>1 && balancenum(root->left)>=0){
        root = rotateright(root);
        root->height=height(root);
        return root;
    }
    if(balance>1 && balancenum(root->left)<0){
        root->left = rotateleft(root->left);
        root=rotateright(root);
        root->height=height(root);
        return root;
    }
    if(balance<-1 && balancenum(root->right)<=0){
        root = rotateleft(root);
        root->height=height(root);
        return root;
    }
    if(balance<-1 && balancenum(root->right)>0){
        root->right = rotateright(root);
        root=rotateleft(root);
        root->height=height(root);
        return root;
    }
    return root;
}

node* min(node* root){
    if(root->left == NULL)return root;
    else return min(root->left);
}

node* max(node* root){
    if(root->right == NULL)return root;
    else return max(root->right);
}

int internalnodes(node* root){
    if(root == NULL)return 0;
    else if(root->left == NULL && root->right == NULL)return 0;
    else return 1+internalnodes(root->left)+internalnodes(root->right);
}

int externalnodes(node* root){
    if(root == NULL)return 0;
    else if(root->left == NULL && root->right == NULL)return 1;
    else return externalnodes(root->left)+externalnodes(root->right);
}   

int totalnodes(node* root){
    if(root == NULL)return 0;
    else return 1+(totalnodes(root->left)+totalnodes(root->right));
}

void inorder(node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void deletetree(node* root){
    if(root != NULL){
        deletetree(root->left);
        deletetree(root->right);
        free(root);
    }
}

node* mirror(node* root){
    if(root != NULL){
        node* temp=root->left;
        root->left=mirror(root->right);
        root->right=mirror(temp);
    }
    return root;
}

node* search(node* root,int data){
    if(root == NULL)return NULL;
    else if(data < root->data)return search(root->left,data);
    else if(data > root->data)return search(root->right,data);
    else return root;
}
