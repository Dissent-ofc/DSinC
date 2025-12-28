#include <stdio.h>
#include <stdlib.h>

// 1. Structure Definition
struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;

// 2. Push Operation (Insert Front)
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    
    if (top == NULL) 
    {
        newNode->next = newNode; // Points to itself, forming the first circle
        top = newNode;
    } 
    else {
        struct Node* temp = top;
        // Traverse to find the last node
        while (temp->next != top) 
        {
            temp = temp->next;
        }
        newNode->next = top;    // New node points to current top
        temp->next = newNode;   // Last node points to new node
        top = newNode;          // Update top to the new node
    }
    printf("Pushed: %d\n", value);
}

// 3. Pop Operation (Delete Front)
void pop() {
    if (top == NULL) 
    {
        printf("Stack Underflow\n");
        return;
    }
    
    // Case 1: Only one node in the stack
    if (top->next == top) 
    {
        printf("Popped: %d\n", top->data);
        free(top);
        top = NULL;
    } 
    // Case 2: Multiple nodes
    else {
        struct Node* temp = top;      // Node to be deleted
        struct Node* last = top;      // Iterator to find the last node
        
        // Traverse to find the last node
        while (last->next != top) 
        {
            last = last->next;
        }
        
        top = top->next;              // Move top to the next node
        last->next = top;             // Update last node to point to new top
        
        printf("Popped: %d\n", temp->data);
        free(temp);                   // Free the old top
    }
}

// 4. Display Operation (Traversal)
void display() {
    if (top == NULL) 
    {
        printf("Stack is Empty\n");
        return;
    }
    
    struct Node* temp = top;
    printf("Stack Elements: \n");
    
    do {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != top);
    printf("\n");
}

// 5. Main Function
int main() {
    int ch, item;
    do
    {
        printf("\n1. Push\t 2. Pop\t 3. Display\t 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("Enter the item to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
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