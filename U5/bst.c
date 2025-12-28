#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node
{
    int data;
    struct Node *llink;
    struct Node *rlink;
};
typedef struct Node *NODE;

// Function to create a new node
NODE getnode(int item) 
{
    NODE getnode = (struct Node*)malloc(sizeof(struct Node));
    if (getnode == NULL) 
        return NULL;
    getnode->data = item;
    getnode->llink = getnode->rlink = NULL;
    return getnode;
}

// Function to Insert a node in BST (Recursive)
NODE insert(NODE root, int item)
{
    // Base Case 1: Empty tree or reached insertion point
    if (root == NULL) 
    {
        NODE temp = getnode(item);
        return temp; // Returns new node (becomes root or child)
    }

    // Recursive Case: Navigate down the tree
    if (item < root->data)
        root->llink = insert(root->llink, item); // Insert in left subtree
    else
        root->rlink = insert(root->rlink, item); // Insert in right subtree

    return root; // Return unchanged root to rebuild the path
}

// Function to perform Search operation in BST
NODE search(NODE root, int item)
{
    NODE cur;
    if(root == NULL) 
    {
        return NULL; // Tree is empty
    }
    cur = root;
    while(cur != NULL) // Loop until we hit the end of a path
    {
        if(item == cur->data) // Found the item
        {
            return cur;
        }
        if(item < cur->data) // Item is smaller, go Left
        {
            cur = cur->llink; 
        }
        else // Item is larger, go Right
        {
            cur = cur->rlink;
        }
    }
    return NULL; // Item not found
}

void preorder(NODE root)
{
    if (root == NULL) return; // Base Case: Stop if node is empty

    printf("%d\t", root->data); // 1. Visit Node (N) - Print data immediately
    preorder(root->llink);      // 2. Go Left (L) - Recursive call
    preorder(root->rlink);      // 3. Go Right (R) - Recursive call
}

//Logic: Visit the Node first, then traverse the Left subtree, then the Right subtree
/*Explanation:

    Check Empty: First, it checks if (root == NULL). If true, it simply returns (stops), preventing an error or infinite loop.

    Print (N): The printf happens before any recursive calls. This is why the root appears first in the output.

    Recurse Left (L): It calls preorder on root->llink. The function pauses here and goes entirely down the llink side until it hits a NULL.

    Recurse Right (R): Once the llink side is finished, it calls preorder on root->rlink */



void postorder(NODE root)
{
    if (root == NULL) return; // Base Case

    postorder(root->llink);     // 1. Go Left (L)
    postorder(root->rlink);     // 2. Go Right (R)
    printf("%d\t", root->data); // 3. Visit Node (N) - Print data last
}

//Logic: Traverse Left, then Right, and visit the Node last
/*Explanation:

    Defer Printing: Notice that printf is the last line.

    Deep Dive: The function immediately calls itself on the llink and then the rlink.

    Effect: This forces the program to go all the way to the bottom (leaves) and print them before it ever prints the root.*/


void inorder(NODE root)
{
    if (root == NULL) return; // Base Case

    inorder(root->llink);       // 1. Go Left (L)
    printf("%d\t", root->data); // 2. Visit Node (N) - Print in the middle
    inorder(root->rlink);       // 3. Go Right (R)
}

//Logic: Traverse Left, visit the Node, then traverse Right. Note: In a Binary Search Tree, this prints values in sorted ascending order.
/*Explanation:

    Sandwich Logic: The printf is "sandwiched" between the llink and rlink calls.

    Flow: It dives down to the leftmost node first. When it hits NULL on the llink, it returns to the previous function call, prints that node, and then attempts to go rlink.*/


/*Summary:
Traversal   ||printf Position   ||Effect
Pre-order   ||Top               ||Root prints first.
In-order    ||Middle            ||"Left child prints, then Parent, then Right."
Post-order  ||Bottom            ||"Children print first, Parent prints last."*/

// Main function
int main() 
{
    struct Node* root = NULL;
    int n, item, ch;
    do
    {
        printf("Menu:\n1. Insert\n2. Search\n3. Traverse\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);

                printf("Enter %d values:\n", n);
                for (int i = 0; i < n; i++) 
                {
                    scanf("%d", &item);
                    root = insert(root, item);
                }
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &item);
                NODE result = search(root, item);
                if (result != NULL)
                    printf("Value %d found in the BST.\n", item);
                else
                    printf("Value %d not found in the BST.\n", item);
                break;
                
            case 3:
                printf("Traversals:\n");
                printf("\nInorder Traversal: ");
                inorder(root);

                printf("\nPreorder Traversal: ");
                preorder(root);

                printf("\nPostorder Traversal: ");
                postorder(root);

                printf("\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (ch!=4);
}


/*
If values are given:
int main() {
    struct Node* root = NULL;
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < sizeof(vals)/sizeof(vals[0]); ++i)
        root = insertNode(root, vals[i]);

    printf("BST Inorder (sorted): "); inorder(root); printf("\n");
    printf("BST Preorder: "); preorder(root); printf("\n");
    printf("BST Postorder: "); postorder(root); printf("\n");
    return 0;
}

*/