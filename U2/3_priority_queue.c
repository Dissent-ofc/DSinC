#include <stdio.h>
#include <stdlib.h>
#define N 4
typedef struct 
{
    int pid;
    int pr;
} job;
job pjob[N];
int front = -1;
int rear = -1;

void enqueue()
{
    int pid, pr;
    if (rear == N - 1)
        printf("Queue Overflow\n");
    else {
        printf("Enter the process id and its priority: ");
        scanf("%d%d", &pid, &pr);
        if (rear == -1)
        {
            rear++;
            front++;
        }
        else
        {
            rear++;
        }
        pjob[rear].pid = pid;
        pjob[rear].pr = pr;
    }
}

void dequeue()
{
    int i,pos=0,max=0;
    if (front ==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            for(i=front;i<=rear;i++)
            {
                if(pjob[i].pr>max)
                {
                    max=pjob[i].pr;
                    pos=i;
                }
            }
            for(i=pos;i<rear;i++)
            {
                pjob[i].pid=pjob[i+1].pid;
                pjob[i].pr=pjob[i+1].pr;
            }
            rear--;
        }
    }
}

void display()
{
    if (front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i=front; i <= rear; i++)
        {
            printf("Process id: %d Priority: %d\n", pjob[i].pid, pjob[i].pr);
        }
    } 
}

void main()
{
    int ch;
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
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