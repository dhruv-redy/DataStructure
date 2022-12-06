#include <stdio.h>
#include <stdlib.h>

struct finalBST
{
    int data;
    struct finalBST *left;
    struct finalBST *right;
};

struct finalBST *create()
{
    struct finalBST *newNode = (struct finalBST *)malloc(sizeof(struct finalBST));
    int data;
    printf("Enter the data\n");
    scanf("%d", &data);
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct finalBST *root, struct finalBST *node)
{
    if (root == NULL)
    {
        root = node;
    }
    else
    {
        if (node->data < root->data)
        {
            if (root->left != NULL)
            {
                insert(root->left, node);
            }
            else
            {
                root->left = node;
            }
        }
        if (node->data > root->data)
        {
            if (root->right != NULL)
            {
                insert(root->right, node);
            }
            else
            {
                root->right = node;
            }
        }
    }
}

void preorder(struct finalBST *root)
{
    if (root == NULL)
    {
        printf("Empty Node\n");
    }
    else
    {
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
