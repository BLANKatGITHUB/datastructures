#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data);
struct Node* insert(struct Node* root, int data);
struct Node* findMin(struct Node* root);
struct Node* delete(struct Node* root, int data);
void inorderTraversal(struct Node* root);
void preorderTraversal(struct Node* root);
void postorderTraversal(struct Node* root);
int height(struct Node* root);
int internalNodes(struct Node* root);
int externalNodes(struct Node* root);
int totalNodes(struct Node* root);
struct Node *mirror(struct Node *root);
void deletetree(struct Node **root);
struct Node* findmax(struct Node* root);

int main() {
    struct Node* root = NULL,*mirrorRoot = NULL;
    int choice, data;
    while(1){
        printf("\n1. Insert\n2. Delete\n3. Inorder Traversal\n4. Preorder Traversal\n5. Postorder Traversal\n6. Height\n7. Internal Nodes\n8. External Nodes\n9. Total Nodes\n10. Mirror\n11. Delete Tree\n12. Find Max\n13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;
            case 3:
                inorderTraversal(root);
                break;
            case 4:
                preorderTraversal(root);
                break;
            case 5:
                postorderTraversal(root);
                break;
            case 6:
                printf("Height of the tree is %d\n", height(root));
                break;
            case 7:
                printf("Number of internal nodes: %d\n", internalNodes(root));
                break;
            case 8:
                printf("Number of external nodes: %d\n", externalNodes(root));
                break;
            case 9:
                printf("Total number of nodes: %d\n", totalNodes(root));
                break;
            case 10:
                mirrorRoot = mirror(root);
                printf("Inorder traversal of mirror tree: ");
                inorderTraversal(mirrorRoot);
                break;
            case 11:
                deletetree(&root);
                root=NULL;
                printf("Tree deleted\n");
                break;
            case 12:
                printf("Maximum element in the tree is %d\n", findmax(root)->data);
                break;
            case 13:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

// Rest of the code...


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* delete(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    } else if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            struct Node* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            struct Node* temp = root;
            root = root->left;
            free(temp);
        } else {
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}  

int internalNodes(struct Node* root) {
    if(root == NULL) {
        return 0;
    }
    else if(root->left == NULL && root->right == NULL) {
        return 0;
    }
    else {
        return internalNodes(root->left) + internalNodes(root->right) + 1;
    }
}

int externalNodes(struct Node* root) {
    if(root == NULL) {
        return 0;
    }
    else if(root->left == NULL && root->right == NULL) {
        return 1;
    }
    else {
        return externalNodes(root->left) + externalNodes(root->right);
    }
}

int totalNodes(struct Node* root) {
    if(root == NULL) {
        return 0;
    }
    else {
        return totalNodes(root->left) + totalNodes(root->right) + 1;
    }
}

struct Node *mirror(struct Node *root) {
 if (root != NULL) {
  struct Node *temp;
  root->left = mirror(root->left);
  root->right = mirror(root->right);
  temp = root->left;
  root->left = root->right;
  root->right = temp;
 }
    return root;
}

void deletetree(struct Node **root) {
 if (*root != NULL) {
  deletetree(&((*root)->left));
  deletetree(&((*root)->right));
  free(*root);
 }
}

struct Node* findmax(struct Node* root) {
if(root == NULL && root->right == NULL) {
return root;
}
else {
return findmax(root->right);
}
}
