#include <stdio.h>
#include <stdlib.h>

// 1. Structure Definition
struct Node 
{
    int data;
    struct Node* next;
};

// Global pointers for Queue
struct Node* front = NULL;
struct Node* rear = NULL;

// 2. Enqueue Operation (Insert Rear)
void enqueue(int value) 
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    
    // Case 1: Queue is empty
    if (front == NULL) 
    {
        front = rear = newnode;
        rear->next = front; // Points to itself to form the circle
    } 
    // Case 2: Queue has elements
    else 
    {
        rear->next = newnode; // Link current rear to new node
        rear = newnode;       // Update rear to the new node
        rear->next = front;   // Maintain circle: rear points back to front
    }
}

// 3. Dequeue Operation (Delete Front)
void dequeue() 
{
    // Case 1: Queue is empty
    if (front == NULL) 
    {
        printf("Queue is empty\n");
        return;
    }
    
    // Case 2: Only one node in the queue
    if (front == rear)
    {
        free(front);
        front = rear = NULL; // Reset both pointers
    } 
    // Case 3: Multiple nodes
    else 
    {
        struct Node* temp = front;
        front = front->next; // Move front forward
        rear->next = front;  // Update rear to point to the new front
        free(temp);          // Delete the old front node
    }
}

// 4. Display Operation
void display() 
{
    if (front == NULL) 
    {
        printf("Queue is Empty\n");
        return;
    }
    
    struct Node* temp = front;
    printf("Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

// 5. Main Function
int main() 
{
    int ch, value;
    do
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 4);
}