#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Structure Definition
struct Node {
    int eno;            // Employee number (as per notes)
    char name[30];
    struct Node *next;  // Pointer to next node
    struct Node *prev;  // Pointer to previous node
};

typedef struct Node NODE;

// 2. Memory Allocation (getnode)
NODE* getnode() 
{
    NODE *temp;
    temp = (NODE*) malloc(sizeof(NODE));
    
    if (temp == NULL) 
    {
        printf("Memory not allocated\n");
        return NULL;
    }
    
    printf("Enter the data (Eno, Name): ");
    scanf("%d %s", &temp->eno, temp->name);
    
    // Initialize both links to NULL
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

// 3. Insert Front
NODE* insert_front(NODE *first) 
{
    NODE *temp;
    temp = getnode();
    
    // Case 1: List is empty
    if (first == NULL) 
    {
        first = temp;
    } 
    // Case 2: List has nodes
    else 
    {
        temp->next = first; // New node points to current first
        first->prev = temp; // Current first's prev points to new node
        first = temp;       // Update first pointer
    }
    return first;
}

// 4. Insert Rear
NODE* insert_rear(NODE *first) 
{
    NODE *temp, *cur;
    temp = getnode();
    
    // Case 1: List is empty
    if (first == NULL) 
    {
        first = temp;
    } 
    // Case 2: Traverse to end
    else 
    {
        cur = first;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = temp;   // Last node points to new node
        temp->prev = cur;   // New node's prev points to last node
    }
    return first;
}

// 5. Delete Front
NODE* delete_front(NODE *first) {
    NODE *cur;
    
    if (first == NULL) 
    {
        printf("List is empty\n");
        return NULL;
    }
    
    cur = first;
    first = first->next; // Move first forward
    
    if (first != NULL) 
    {
        first->prev = NULL; // New first node's prev must be NULL
    }
    
    free(cur);
    return first;
}

// 6. Delete Rear
NODE* delete_rear(NODE *first) {
    NODE *cur, *prev;
    
    if (first == NULL) 
    {
        printf("List is empty\n");
        return NULL;
    }
    
    // Case: Only one node
    if (first->next == NULL) 
    {
        free(first);
        return NULL;
    } 
    
    // Case: Multiple nodes
    // Note: The handwritten notes use a 'prev' variable for traversal
    // even though 'cur->prev' exists in a DLL structure.
    prev = NULL;
    cur = first;
    while (cur->next != NULL) 
    {
        prev = cur;
        cur = cur->next;
    }
    
    prev->next = NULL; // Disconnect the last node
    free(cur);         // Free memory
    return first;
}

// 7. Display (Traverse)
NODE* display(NODE *first) {
    NODE *cur;
    int count = 0;
    
    if (first == NULL) 
    {
        printf("List is empty\n");
    } 
    else 
    {
        cur = first;
        printf("\nEMPLOYEE DATA:\n");
        while (cur != NULL) {
            printf("%d\t%s\n", cur->eno, cur->name);
            count++;
            cur = cur->next;
        }
        printf("No of nodes is %d\n", count);
    }
    return first;
}

// 8. Main Function
int main() {
    int ch;
    NODE *first = NULL;
    
    do
    {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1: first = insert_front(first); break;
            case 2: first = insert_rear(first); break;
            case 3: first = delete_front(first); break;
            case 4: first = delete_rear(first); break;
            case 5: display(first); break;
            case 6: exit(0);
            default: printf("Enter valid choice\n");
        }
    } while (ch != 6);
}