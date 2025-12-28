#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Structure Definition
typedef struct student
{
    char USN[10];
    char name[30];
    char branch[5];
    int sem;
    char phno[15];
    struct student *link;
} NODE;

// 2. Memory Allocation Function
NODE* getnode()
{
    NODE *x;
    x = (NODE*) malloc(sizeof(NODE)); // Allocate memory
    
    printf("\n Enter USN, Name, Branch, Sem, Ph.No \n");
    scanf("%s", x->USN);
    scanf("%s", x->name);
    scanf("%s", x->branch);
    scanf("%d", &x->sem);
    scanf("%s", x->phno);
    
    x->link = NULL; // Safety step
    return x;
}

// 3. Display Function
NODE* display(NODE* first)
{
    NODE *cur;
    int count = 0;
    
    if (first == NULL)
    {
        printf("\n No student data / List is Empty \n");
        return first;
    }
    
    printf("\n ---- STUDENT DATA ---- \n");
    printf("\n USN \t NAME \t BRANCH \t SEM \t Ph.No \n");
    cur = first;
    while (cur != NULL)
    {
        printf("\n %s \t %s \t %s \t %d \t %s", cur->USN, cur->name, cur->branch, cur->sem, cur->phno);
        cur = cur->link;
        count++;
    }
    printf("\n The no. of nodes in the list is: %d \n", count);
    return first;
}

// 4. Create / Insert Front Function
NODE* insert_front(NODE* first)
{
    NODE* temp;
    temp = getnode(); // Create new node
    
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        temp->link = first; // Point new node to old first
        first = temp;       // Update first to point to new node
    }
    return first;
}

// 5. Insert Rear Function
NODE* insert_rear(NODE* first)
{
    NODE *cur, *temp;
    temp = getnode();
    
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        cur = first;
        while (cur->link != NULL) // Traverse to end
        {
            cur = cur->link;
        }
        cur->link = temp; // Attach new node at the end
    }
    return first;
}

// 6. Delete Front Function
NODE* del_front(NODE* first)
{
    NODE* cur;
    if (first == NULL)
    {
        printf("\n List is Empty \n");
    }
    else
    {
        cur = first;          // Mark node to delete
        first = first->link;  // Move head to next node
        free(cur);            // Delete old head
        printf("\n Front (first) node is deleted \n");
    }
    return first;
}

// 7. Delete Rear Function
NODE* del_rear(NODE* first)
{
    NODE *cur, *prev;
    
    if (first == NULL)
    {
        printf("\n List is empty \n");
        return first;
    }
    
    if (first->link == NULL) // Only one node
    {
        printf("\n Last (end) entry is deleted \n");
        free(first);
        return NULL;
    }
    
    // Traverse to find the last node
    prev = NULL;
    cur = first;
    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    
    prev->link = NULL; // Disconnect last node
    free(cur);         // Delete last node
    printf("\n Last (end) entry is deleted \n");
    return first;
}

// 9. Main Function
int main()
{
    int ch, n, i;
    NODE* first = NULL; // Initialize list as empty
    
    printf("\n * Student Database * \n");
    
    do
    {
        printf("\n 1. Create/Insert Front \t 2. Display \t 3. Insert Rear");
        printf("\n 4. Delete Front \t 5. Delete Rear \t 6. Stack Demo \t 7. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch)
        {
            case 1: 
                printf("\n How many students to create? ");
                scanf("%d", &n);
                for(i=0; i<n; i++)
                    first = insert_front(first);
                break;
            case 2: first = display(first); break;
            case 3: first = insert_rear(first); break;
            case 4: first = del_front(first); break;
            case 5: first = del_rear(first); break;
            case 7: exit(0);
            default: printf("Enter valid choice \n");
        }
    } while (ch != 7);
    return 0;
}