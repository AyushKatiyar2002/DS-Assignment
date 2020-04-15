/*C)	Write a C program that uses stack operations to convert a given infix expression into its postfix Equivalent, Implement the stack using an array*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char* stack[100];
int top;
void push(char* exp)
{
    stack[top] = exp;
    top++;
}

void pop()
{
    top--;
}
void postToIn(char *expr)
{
    char temp[100], str[100];

    for(int i = 0; i < strlen(expr); i++)
    {
        if(isalnum(expr[i]))
        {
            temp[0] = expr[i];
            temp[1] = '\0';
            push(temp);
        }
        else
        {
            temp[0] = '(';
            temp[1] = '\0';

            strcat(temp, stack[top]);

            str[0] = expr[i];
            str[1] = '\0';
            strcat(temp, str);

            strcat(temp, stack[top]);

            pop();
            pop();

            temp[strlen(temp)] = ')';
            temp[strlen(temp)+1] = '\0';

            push(temp);
        }
    }
    printf("Converted: %s", temp);
}
int main()
{
    top = 0;
    char str[100];
    strcpy(str, "ABC+*D");
    postToIn(str);
}
