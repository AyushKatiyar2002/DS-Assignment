/*H)	Write a C program that uses functions to perform the following:
a.	Create a binary search tree of integers.
b.	Traverse the above Binary search tree non recursively in order
c.	Calculate its height
*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
 struct Node *lchild;
 int data;
 struct Node *rchild;
}*root=NULL;
void Insert(int key)
{
 struct Node *t=root;
 struct Node *r=NULL,*p;

 if(root==NULL)
 {
 p=(struct Node *)malloc(sizeof(struct Node));
 p->data=key;
 p->lchild=p->rchild=NULL;
 root=p;
 return;
 }
 while(t!=NULL)
 {
 r=t;
 if(key<t->data)
 t=t->lchild;
 else if(key>t->data)
 t=t->rchild;
 else
 return;
 }
 p=(struct Node *)malloc(sizeof(struct Node));
 p->data=key;
 p->lchild=p->rchild=NULL;

 if(key<r->data) r->lchild=p;
 else r->rchild=p;
}



int height(struct Node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->lchild);
        int rheight = height(node->rchild);

        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
int main()
{
 int i;
 for(i=0;i<26;i++)
    Insert(i);
 printf("\nHeight is;%d\n",height(root));
 return 0;
}
