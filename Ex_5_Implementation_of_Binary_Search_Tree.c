#include<stdio.h>
#include<stdlib.h>
struct BST {
     int data;
    struct BST *lchild;
     struct BST *rchild;
};
typedef struct BST * NODE;
NODE create() {
     NODE temp;
     temp = (NODE) malloc(sizeof(struct BST));
     printf("\nEnter The value: ");
     scanf("%d", &temp->data);
     temp->lchild = NULL;
     temp->rchild = NULL;
     return temp;
}
void insert(NODE root, NODE newnode);
void inorder(NODE root);
void preorder(NODE root);
void postorder(NODE root);
void search(NODE root);
void insert(NODE root, NODE newnode) {
     /*Note: if newnode->data == root->data it will be skipped. No duplicate nodes are allowed */
     if (newnode->data < root->data) {
         if (root->lchild == NULL)
             root->lchild = newnode;
         else
             insert(root->lchild, newnode);
     }
     if (newnode->data > root->data) {
         if (root->rchild == NULL)
             root->rchild = newnode;
         else
             insert(root->rchild, newnode);
     }
}
void inorder(NODE root) {
     if (root != NULL) {
         inorder(root->lchild);
         printf("%d\t", root->data);
         inorder(root->rchild);
     }
}
void preorder(NODE root) {
     if (root != NULL) {
         printf("%d\t", root->data);
         preorder(root->lchild);
         preorder(root->rchild);
     }
}
void postorder(NODE root) {
     if (root != NULL) {
         postorder(root->lchild);
         postorder(root->rchild);
         printf("%d\t", root->data);
     }
}
void search(NODE root) {
     int key;
     NODE temp = root;
     printf("\nEnter element to be searched: ");
     scanf("%d", &key);
     while (temp != NULL) {
         if (key == temp->data) {
             printf("\nElement %d found\n", key);
             return;
         }
         if (key < temp->data)
             temp = temp->lchild;
         else
             temp = temp->rchild;
     }
     printf("\nElement %d not found\n", key);
}
int main() {
     int choice;
     NODE root = NULL, newnode;
     while (1) {
         printf("\n1. Insert 2. Inorder 3. Preorder 4. Postorder 5. Search 6. Exit\n");
         printf("Enter choice: ");
         scanf("%d", &choice);
         switch (choice) {
             case 1:
                 newnode = create();
                 if (root == NULL)
                     root = newnode;
                 else
                     insert(root, newnode);
                 break;
             case 2:
                 printf("\nInorder traversal: ");
                 inorder(root);
                 printf("\n");
                 break;
             case 3:
                 printf("\nPreorder traversal: ");
                 preorder(root);
                 printf("\n");
                 break;
             case 4:
                 printf("\nPostorder traversal: ");
                 postorder(root);
                 printf("\n");
                 break;
             case 5:
                 search(root);
                 break;
             case 6:
                 exit(0);
         }
     }
}
