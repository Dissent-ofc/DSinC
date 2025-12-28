#include <stdio.h>
#include <stdlib.h>

// 1. Structure Definition
typedef struct student
{
    int uno;            // University Number / ID
    char name[20];      // Name
    struct student *link;
} NODE;

// 2. Memory Allocation (getnode)
NODE* getnode()
{
    NODE *x;
    x = (NODE*) malloc(sizeof(NODE)); // Allocate memory
    
    printf("Enter student details (ID Name): ");
    scanf("%d %s", &x->uno, x->name);
    
    x->link = NULL; // Safety step
    return x;
}

// 3. Enqueue Operation (Insert Rear)
NODE* insert_rear(NODE *first)
{
    NODE *temp, *cur;
    temp = getnode(); // Create the new person/node
    
    // Case 1: Queue is empty
    if (first == NULL)
    {
        first = temp;
    }
    // Case 2: Queue has people
    else
    {
        cur = first;
        // Traverse to the end of the line
        while (cur->link != NULL)
        {
            cur = cur->link;
        }
        cur->link = temp; // Attach new person at the back
    }
    return first;
}

// 4. Dequeue Operation (Delete Front)
NODE* del_front(NODE *first)
{
    NODE *cur;
    
    // Case 1: Queue is empty
    if (first == NULL)
    {
        printf("\n List is Empty \n");
    }
    // Case 2: Remove the person at the front
    else
    {
        cur = first;          // Mark the first node
        first = first->link;  // Move the 'first' pointer to the second node
        free(cur);            // Delete the old first node
        printf("\n Front (first) node is deleted \n");
    }
    return first;
}

// 5. Display Operation
NODE* display(NODE *first)
{
    NODE *cur;
    if (first == NULL)
    {
        printf("Queue is Empty \n");
    }
    else
    {
        cur = first;
        printf("\n Queue Contents: \n");
        while (cur != NULL)
        {
            printf("%d %s \n", cur->uno, cur->name);
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
    
    while (1) // Infinite Loop
    {
        printf("\n 1. Enqueue (Insert Rear) \n 2. Dequeue (Delete Front) \n 3. Display \n 4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch)
        {
            case 1: first = insert_rear(first); break;
            case 2: first = del_front(first); break;
            case 3: display(first); break;
            case 4: exit(0);
            default: printf("Invalid choice \n");
        }
    }
    return 0;
}