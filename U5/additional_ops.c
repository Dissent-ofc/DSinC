/*1]    Finding Maximum Item
The Logic: In a Binary Search Tree, larger values are always to the Right. Therefore, the maximum value in the entire tree is located at the right-most node.
Start at the first.
Keep moving to the rlink (right child) until you reach a node that has no right child.
That node contains the maximum value.
*/

NODE maximum(NODE first) {
    NODE cur;
    if (first == NULL) return first; // Tree is empty

    cur = first;
    // Loop until we reach the right-most node
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    return cur; // This is the max node
}

/*2]    Finding Minimum Item
The Logic: Conversely, smaller values are always to the Left. The minimum value is located at the left-most node.
Start at the root.
Keep moving to the llink (left child) until you reach a node with no left child.
That node contains the minimum value.*/

NODE minimum(NODE first) {
    NODE cur;
    if (first == NULL) return first;

    cur = first;
    // Loop until we reach the left-most node
    while (cur->llink != NULL) {
        cur = cur->llink;
    }
    return cur; // This is the min node
}

/*3]    Finding Height of a Tree
The Logic: The height is the number of edges on the longest path from the root to a leaf.
This is solved recursively.
The height of a node is 1 + max(height of left child, height of right child).
Base Case: If a node is NULL, its height is -1 (or 0 depending on definition; your notes use -1 for empty to make a single node height 0)*/

int height(NODE root) {
    if (root == NULL) return -1; // Base case for empty tree

    // Recursively calculate height of left and right subtrees
    // and take the maximum of the two, then add 1.
    return 1 + max(height(root->llink), height(root->rlink));
}

/*4]    Counting Total Nodes
The Logic: To count all nodes, you simply traverse the entire tree (visit every node) and increment a counter.
The code uses a global variable count.
It traverses the tree (Pre-order/In-order/Post-order doesn't matter here) and increments count for every non-null node visited.*/

void count_nodes(NODE root) {
    if (root == NULL) return;

    count_nodes(root->llink); // Visit left
    count++;                  // Increment global counter
    count_nodes(root->rlink); // Visit right
}

/*5]    Counting Leaf Nodes
The Logic: A Leaf Node is a node that has no children (both left and right links are NULL).
Traverse the tree recursively.
At every node, check: if (root->llink == NULL && root->rlink == NULL).
If true, increment the count.*/

void count_leaf(NODE root) {
    if (root == NULL) return;

    // Check if it's a leaf
    if (root->llink == NULL && root->rlink == NULL) {
        count++; // Found a leaf!
    }

    count_leaf(root->llink); // Check left subtree
    count_leaf(root->rlink); // Check right subtree
}