#include <stdio.h>
#include <stdlib.h>
//#define n 5;

int stack[5];
int top = -1;

void push()
{
    if (top == 5 - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        top++;
        int data;
        printf("Enter the value\n");
        scanf("%d", &data);
        stack[top] = data;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        int removeVal;
        removeVal = stack[top];
        top--;
        printf("Value removed is %d\n", removeVal);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main(int argc, char const *argv[])
{
    int option;
    while (1)
    {
        printf("Choose the option\n");
        printf("Push\n");
        printf("Pop\n");
        printf("Display\n");
        printf("Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            push();
            break;
        }

        case 2:
        {
            pop();
            break;
        }

        case 3:
        {
            display();
            break; 
        }

        case 4: {
            exit(0);
            break;
        }

        default:
        {
            printf("Try again\n");
            break;
        }
        }
    }
    return 0;
}