#include <stdio.h>
#include <stdlib.h>
#define N 5
int stack[N];
int top = -1;

void push()
{
    int x;
    printf("Enter value to be pushed: ");
    scanf("%d", &x);
    if (top == N-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

void pop()
{
    int item;
    if (top==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        item=stack[top];
        top--;
        printf("%d Popped from stack\n", item);
    }
}

void display()
{
    int i;
    for (i=top;i>=0;i--)
    {
        printf("%d\n", stack[i]);
    }
}

void main()
{
    int ch;
    do
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invalid choice\n");
        }
    } while (ch!=4);
    {
        getchar();
    }
}