#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure Definition
typedef struct student 
{
    char usn[10];
    char name[30];
    struct student *link;
}NODE;

// 1. Memory Allocation and Node Creation
NODE* getnode() 
{
    NODE *x;
    x = (NODE*) malloc(sizeof(NODE));
    if (x == NULL) 
    {
        printf("Memory not allocated\n");
        return NULL;
    }
    printf("\nEnter USN, Name:\n");
    scanf("%s", x->usn);
    scanf("%s", x->name);
    x->link = NULL;
    return x;
}

// 2. Insert Front
NODE* insert_front(NODE *first) 
{
    NODE *cur, *temp;
    temp = getnode();
    
    if (first == NULL) 
    {
        first = temp;
        temp->link = first; // Points to itself
    } 
    else 
    {
        cur = first;
        // Traverse to the last node to update its link
        while (cur->link != first) 
        {
            cur = cur->link;
        }
        cur->link = temp;    // Last node points to new node
        temp->link = first;  // New node points to current first
        first = temp;        // Update first pointer
    }
    return first;
}

// 3. Insert Rear
NODE* insert_rear(NODE *first) 
{
    NODE *cur, *temp;
    temp = getnode();
    
    if (first == NULL) 
    {
        first = temp;
        temp->link = first;
    } 
    else 
    {
        cur = first;
        while (cur->link != first) 
        {
            cur = cur->link;
        }
        cur->link = temp;    // Last node points to new node
        temp->link = first;  // New node points back to first
    }
    return first;
}

// 4. Delete Front
NODE* delete_front(NODE *first) {
    NODE *cur;
    if (first == NULL) 
    {
        printf("Nothing present to delete\n");
        return NULL;
    } 
    
    if (first->link == first) 
    { // Only one node
        free(first);
        return NULL;
    } 
    else 
    {
        cur = first;
        // Traverse to find the last node
        while (cur->link != first) 
        {
            cur = cur->link;
        }
        cur->link = first->link; // Last node points to the 2nd node
        cur = first;             // Hold the node to be deleted
        first = first->link;     // Move first pointer to next node
        free(cur);
    }
    return first;
}

// 5. Delete Rear
NODE* delete_rear(NODE *first) 
{
    NODE *cur, *prev;
    if (first == NULL) 
    {
        printf("Nothing present to delete\n");
        return NULL;
    }
    
    if (first->link == first) { // Only one node
        free(first);
        return NULL;
    } 
    else 
    {
        prev = NULL;
        cur = first;
        // Traverse to find the second to last node
        while (cur->link != first) 
        {
            prev = cur;
            cur = cur->link;
        }
        prev->link = first; // Second to last node becomes last, points to first
        free(cur);
    }
    return first;
}

// 6. Display (Traverse)
NODE* display(NODE *first) 
{
    NODE *cur;
    int count = 0;
    
    if (first == NULL) 
    {
        printf("No elements present to display\n");
    } 
    else 
    {
        cur = first;
        printf("\nSTUDENT DATA:...\n");
        printf("\nUSN \t NAME \n");
        
        // Loop until we come back to the start
        do 
        {
            printf("\n%s\t%s", cur->usn, cur->name);
            cur = cur->link;
            count++;
        } while (cur != first);
        
        printf("\nThe no of nodes in the list is: %d\n", count);
    }
    return first;
}

// Main Function
int main() 
{
    int ch, i, n;
    NODE *first = NULL;
    
    printf("\n*---- Student Database ----*\n");
    
    do 
    {
        printf("\n1. Create (Insert Front multiple)\n2. Insert-front\n3. Insert-Rear\n4. Delete-front\n5. Delete-Rear\n6. Display\n7. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        
        switch (ch) 
        {
            case 1:
                printf("\nHow many students data you want to create: ");
                scanf("%d", &n);
                for(i = 0; i < n; i++)
                    first = insert_front(first); // Note: PDF calls 'create' but defines it similar to insert_front
                break;
            case 2:
                first = insert_front(first);
                break;
            case 3:
                first = insert_rear(first);
                break;
            case 4:
                first = delete_front(first);
                break;
            case 5:
                first = delete_rear(first);
                break;
            case 6:
                display(first);
                break;
            case 7:
                exit(0);
            default:
                printf("Enter valid choice\n");
        }
    } while (ch != 7);
}