/* A)	Write a C program that uses functions to perform the following:
a.	Create a singly linked list of integers.
b.	Delete a given integer from the above linked list.
c.	Display the contents of the above list after deletion. */

#include <stdio.h>
#include <stdlib.h>
struct Node  // creating node
{
 int data;  // storing data
 struct Node *link;  // linking to next data
}*head=NULL;   // creating/assigning head to null
void create(int a[],int n)
{
 int i;
 struct Node *temp,*last;
 head=(struct Node *)malloc(sizeof(struct Node));
 head->data=a[0];
 head->link=NULL;
 last=head;

 for(i=1;i<n;i++)
 {
 temp=(struct Node*)malloc(sizeof(struct Node));
 temp->data=a[i];
 temp->link=NULL;
 last->link=temp;
 last=temp;
 }
}

void display(struct Node *t) // displaying array
{
 while(t!=NULL)
 {
 printf("%d ",t->data);
 t=t->link;
 }
}
int Delete_n(struct Node *p,int index,int n)
{
 struct Node *q=NULL;
 int x=-1,i; // storing deleted element

 if(index < 1 || index > n)  // validating index
 return -1;
 if(index==1)
 {
 q=head;
 x=head->data;
 head=head->link;
 free(q);
 return x;
 }
 else
 {
 for(i=0;i<index-1;i++)
 {
 q=p;
 p=p->link;
 }
 q->link=p->link;
 x=p->data;
 free(p);
 return x;

 }
}
int main()
{
 int n,i,index;
 printf("Enter the size of linked list\n");
 scanf("%d",&n);
 int a[n];
 printf("\nEnter the elements to be entered\n");
 for(i=0;i<n;i++)
    scanf("%d",a[i]);

 create(a,n);
 printf("\nLinked list before deletion is\n");
 display(head);
 printf("\nEnter the index from where you want to delete element\n");
 scanf("%d",&index);
 printf("Deleted elemnt is : %d\n",Delete_n(head,index,n));
 printf("\nNew linked list is\n");
 display(head);

 return 0;
}
