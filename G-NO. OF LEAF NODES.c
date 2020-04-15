/*G)	Write a C program that to calculate:
a.	Number of Leaf and non Leaf in a Binary Tree
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node* left, *right;

};

/*
 * Function to create new nodes
 */

struct node* createnode(int key)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = key;
    newnode->left = NULL;
    newnode->right = NULL;

    return(newnode);
}

/*
 * Function to count number of leaf nodes
 */

int count = 0;
int leafnodes(struct node* newnode)
{

    if(newnode != NULL)
    {
        leafnodes(newnode->left);
        if((newnode->left == NULL) && (newnode->right == NULL))
        {
            count++;
        }
        leafnodes(newnode->right);
    }
    return count;

}
int nonleafnodes(struct node* newnode)
{

    if(newnode != NULL)
    {
        nonleafnodes(newnode->left);
        if((newnode->left != NULL) || (newnode->right != NULL))
        {
            count++;
        }
        nonleafnodes(newnode->right);
    }
    return count;

}
/*
 * Main Function
 */

int main()
{

    struct node *newnode = createnode(25);
    newnode->left = createnode(27);
    newnode->right = createnode(19);
    newnode->left->left = createnode(17);
    newnode->left->right = createnode(91);
    newnode->right->left = createnode(13);
    newnode->right->right = createnode(55);
    printf("Number of leaf nodes in Tree are\t%d\n",leafnodes(newnode));

    printf("No of non leaf nodes are: %d\n",nonleafnodes(newnode));
    return 0;
}
