// 66070501013 Thinnaphat Kanchina
#include <stdio.h>
#include <stdlib.h>

// An AVL tree node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int height(struct Node *N)
{
    if (N == NULL) // this is why we need this function
        return 0;
    return N->height;
}

// max of 2 value (it will be used a lot for height comparison)
int maxof(int a, int b)
{
    return (a > b) ? a : b;
}

struct Node *newNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *temp = x->right;

    // Perform rotation
    x->right = y;
    y->left = temp; // temp for rotation

    // Update heights
    y->height = maxof(height(y->left), height(y->right)) + 1;
    x->height = maxof(height(x->left), height(x->right)) + 1;

    // Return new root
    return x; // the node will be switch to another node
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *temp = y->left; // temp for rotation

    // Perform rotation
    y->left = x;
    x->right = temp;

    // Update heights
    x->height = maxof(height(x->left), height(x->right)) + 1;
    y->height = maxof(height(y->left), height(y->right)) + 1;

    // Return new root
    return y; // the node will be switch to another node
}

// Get Balance factor of node N
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    
    return height(N->left) - height(N->right);
}

struct Node *insert(struct Node *node, int key)
{
    /* 1. Perform the normal BST insertion */
    // hint: same as the bst insertion

    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node: because we insert the node and create the new height*/
    node->height = 1 + maxof(height(node->left), height(node->right));

    /* 3. Get the balance factor of this ancestor node to check whether this node became unbalanced */

    int balance = getBalance(node); // try above function

    // See the slide and match the rotation side.
    // Left Left Case (LL)
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case (RR)
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case (LR)
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case (RL)
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // return the (unchanged) node pointer if the tree is already balance
    return node;
}

// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

/* Main 💀💀💀 */
int main()
{
    struct Node *root = NULL;
    int n, data;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);

    return 0;
}