#include <stdio.h>
#include <stdlib.h>

struct tree
{
    struct tree *right;
    struct tree *left;
    int data;
};

struct tree *createNode()
{
    struct tree *newNode = (struct tree *)malloc(sizeof(struct tree));
    int data;
    printf("Enter the value");
    scanf("%d", &data);
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

void insert(struct tree *root, struct tree *newNode)
{

    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        if (newNode->data < root->data)
        {
            if (root->left != NULL)
            {
                insert(root->left, newNode);
            }
            else
                root->left = newNode;
        }

        if (newNode->data > root->data)
        {
            if (root->right != NULL)
            {
                insert(root->right, newNode);
            }
            else
                root->right = newNode;
        }
    }
}

void preorder(struct tree *root)
{
    if (root == NULL)
    {
        printf("Empty tree");
        return;
    }
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(int argc, char const *argv[])
{

    while (1)
    {
        int value;
        struct tree *root;
        printf("Enter the value\n");
        printf("Preorder\n");
        printf("End\n");
        scanf("%d", &value);
        switch (value)
        {
        case 1:
        {
            struct tree *newNode = createNode();
            if (root == NULL)
            {
                root = newNode;
            }
            else
            {
                insert(root, newNode);
            }
            break;
        }
        case 2:
        {
            preorder(root);
            break;
        }
        case 3:
        {
            exit(0);
            break;
        }
        default:
        {
            printf("Error");
        }
        }
    }

    return 0;
}
