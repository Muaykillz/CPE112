// 66070501013 Thinnaphat Kanchina

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// add data to the tree with preorder
int add(TreeNode **root, char data)
{
    int is_added = 0;
    if (*root == NULL)
    {
        *root = (TreeNode *)malloc(sizeof(TreeNode));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return 1;
    }
    else if ((*root)->data == '+' || (*root)->data == '-')
    {
        is_added = add(&(*root)->left, data);
        if (is_added == 0)
        {
            is_added = add(&(*root)->right, data);
        }
    }
    else
    {
        return 0;
    }

    return is_added;
}

// print the tree with postorder
void postorder(TreeNode *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

int main()
{
    TreeNode *root = NULL;

    char expression[100];
    scanf("%s", expression);

    for (int i = 0; expression[i] != '\0'; i++)
    {
        add(&root, expression[i]);
    }
    postorder(root);

    return 0;
}
