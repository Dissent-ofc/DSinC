//204_Shivam
#include <stdio.h>
#include <stdlib.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;

void enqueue()
{
    int x;
    printf("Enter the element to be enqueued: ");
    scanf("%d", &x);
    if (rear==N-1)
    {
        printf("Queue Overflow\n");
    }
    else if (front==-1 && rear ==-1)
    {
        front = rear = 0;
        queue[rear]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}

void dequeue()
{
    if (front==-1 && rear==-1)
    {
        printf("Queue Underflow\n");
    }
    else if (front==rear)
    {
        front=rear=-1;
    }
    else
    {
        printf("Dequeued element: %d\n", queue[front]);
        front++;
    }
}

void display()
{
    if (front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i=front; i<=rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void main()
{
    int ch;
    do
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    } 
    while (ch!=4);
    {
        getchar();
    }
}