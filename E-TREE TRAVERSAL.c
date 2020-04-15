/*E)	Write a C program that uses functions to perform the following:
a.	Create a binary search tree of characters.
b.	Traverse the above Binary search tree recursively in Postorder, inorder and Preorder
*/
#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
//declaration of the tree element right, left and data type
struct node
{
  char data;
  struct node *left;
  struct node *right;
}*Node;

//Creating root node
struct node *create()
{
  char x;
  //struct node *newnode;
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  printf("Enter the data for the nodes (0 for no data)");
  scanf("%c",&x);
  newnode->data=x;
  if(x==0)
  {
    printf ("Not entered any data\n");
    return NULL;
  }
  printf("Enter the data of left child of the rooted data : %c\t",newnode->data);
  newnode->left=create();
  printf("Enter the data of right child of the rooted data : %c\t",newnode->data);
  newnode->right=create();
  return newnode;
}

//Inorder traversing using recursion
void Inorder(struct node *root)
{
  if(root)
  {
    Inorder(root->left);
    printf ("%c\t",root->data);
    Inorder(root->right);
  }
}

//Postorder traversing using recursion
void postorder(struct node *root)
{
  if(root)
  {
    postorder(root->left);
    postorder(root->right);
    printf ("%d  ",root->data);
  }
}

//Preorder traversing using recursion
void preorder(struct node *root)
{
  if(root)
  {
    printf ("%d  ",root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

int main ()
  {
    //struct node *t,*root;
    struct node *root=create();
    struct node *t=root;
    //traverse(t);
    printf("Preorder Traversal : \n");
    preorder(root);
    printf("Inorder Traversal : \n");
    Inorder(root);
    printf("postorder Traversal : \n");
    postorder(root);
    return 0;
  }
