#include <stdio.h>
#include <stdlib.h>

// 1. Structure Definition
typedef struct student
{
    int ino;            // ID number
    char name[26];      // Name
    struct student *link;
} NODE;

// 2. Memory Allocation (getnode)
NODE* getnode()
{
    NODE *x;
    x = (NODE*) malloc(sizeof(NODE)); // Request memory
    
    printf("Enter student details (ID Name): ");
    scanf("%d %s", &x->ino, x->name);
    
    x->link = NULL; // Initialize link to NULL
    return x;
}

// 3. Push Operation (Insert Rear)
NODE* insert_rear(NODE *first)
{
    NODE *temp, *cur;
    temp = getnode(); // Create the new node
    
    // Case 1: Stack is empty
    if (first == NULL)
    {
        first = temp;
    }
    // Case 2: Stack has data
    else
    {
        cur = first;
        // Traverse to the last node
        while (cur->link != NULL)
        {
            cur = cur->link;
        }
        // Attach new node to the end
        cur->link = temp;
    }
    return first;
}

// 4. Pop Operation (Delete Rear)
NODE* delete_rear(NODE *first)
{
    NODE *cur, *prev;
    
    // Case 1: Stack is empty
    if (first == NULL)
    {
        printf("List is Empty\n");
        return first;
    }
    
    // Case 2: Only one node in Stack
    if (first->link == NULL)
    {
        printf("Deleted node: %d\n", first->ino);
        free(first);
        return NULL;
    }
    
    // Case 3: Multiple nodes (Traverse to end)
    prev = NULL;
    cur = first;
    while (cur->link != NULL)
    {
        prev = cur;       // 'prev' stays one step behind
        cur = cur->link;  // 'cur' moves to next
    }
    
    // 'cur' is now at the last node (Top of stack)
    // 'prev' is at the second-to-last node
    printf("Deleted node: %d\n", cur->ino);
    prev->link = NULL; // Break the link
    free(cur);         // Release memory
    
    return first;
}

// 5. Display Operation
NODE* display(NODE *first)
{
    NODE *cur;
    if (first == NULL)
    {
        printf("List is Empty \n");
    }
    else
    {
        cur = first;
        printf("\n Stack Contents: \n");
        while (cur != NULL)
        {
            printf("%d %s \n", cur->ino, cur->name);
            cur = cur->link;
        }
    }
    return first;
}

// 6. Main Function
int main()
{
    NODE *first = NULL;
    int ch;
    
    // Menu Loop
    while (1)
    {
        printf("\n 1. Push (Insert Rear) \n 2. Pop (Delete Rear) \n 3. Display \n 4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch)
        {
            case 1: first = insert_rear(first); break;
            case 2: first = delete_rear(first); break;
            case 3: display(first); break;
            case 4: exit(0);
            default: printf("Invalid choice \n");
        }
    }
    return 0;
}