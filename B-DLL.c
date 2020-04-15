/*B)	Write a C program that uses functions to perform the following:
a.	Create a doubly linked list of integers.
b.	Delete a given integer from the above doubly linked list.
c.	Display the contents of the above list after deletion
*/
#include <stdio.h>
#include <stdlib.h>
struct Node  // creating node
{
 struct Node *prev;// linking to previous data
 int data;  // storing data
 struct Node *next;  // linking to next data
}*head=NULL;   // creating/assigning head to null
void create(int a[],int n)
{
 int i;
 struct Node *temp,*last;
 head=(struct Node *)malloc(sizeof(struct Node));
 head->data=a[0];
 head->next=NULL;
 last=head;

 for(i=1;i<n;i++)
 {
 temp=(struct Node*)malloc(sizeof(struct Node));
 temp->data=a[i];
 temp->next=last->next;
 temp->prev=last;
 last->next=temp;
 last=temp;
 }
}

void print(struct Node *t) // displaying array
{
 while(t!=NULL)
 {
 printf("%d ",t->data);
 t=t->next;
 }
 printf("\n");
}
int Delete(struct Node *p,int index,int n)
{
 struct Node *q=NULL;
 int x=-1,i;

 if(index < 1 || index > n)  // validating index
 return -1;
 if(index==1)
 {
 q=head;
 head=head->next;
 if(head)head->prev=NULL;
     x=head->data;

 free(q);
 return x;
 }
 else
 {
 for(i=0;i<index-1;i++)
 p=p->next;
 p->prev->next=p->next;
 if(p->next)
 p->next->prev=p->prev;
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
    scanf("%d",&a[i]);

 create(a,n);
 printf("\nLinked list before deletion is\n");
 print(head);
 printf("\nEnter the index from where you want to delete element\n");
 scanf("%d",&index);
 printf("Deleted elemnt is : %d\n",Delete(head,index,n));
 printf("\nNew linked list is\n");
 print(head);

 return 0;
}
