#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};

struct BST *create()
{
    struct BST *temp;
    int x;
    printf("\nEnter data : ");
    scanf("%d", &x);
    temp = (struct BST *)malloc(sizeof(struct BST));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(struct BST *root, struct BST *temp)
{
    if (temp->data < root->data)
    {
        if (root->left != NULL)
        {
            insert(root->left, temp);
        }
        else
        {
            root->left = temp;
        }
    }
    else if (temp->data > root->data)
    {
        if (root->right != NULL)
        {
            insert(root->right, temp);
        }
        else
        {
            root->right = temp;
        }
    }
}

void inorder(struct BST *root)
{
    if (root == NULL)
    {
        printf("Empty tree");
        return;
    }
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct BST *root)
{
    if (root == NULL)
    {
        printf("Empty tree");
        return;
    }
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void preorder(struct BST *root)
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

int Largest(struct BST *root)
{
    if (root == NULL)
    {
        printf("Empty tree");
        return 0;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    int large = root->data;
    return large;
}

int Smallest(struct BST *root)
{
    if (root == NULL)
    {
        printf("Empty tree");
        return 0;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    int small = root->data;
    return small;
}

int main()
{
    int ch;
    struct BST *root = NULL;
    while (1)
    {
        printf("\nEnter the choices :\n");
        printf("\n1: Insertion\n");
        printf("\n2: Inorder traversal and display\n");
        printf("\n3: Postorder traversal and display\n");
        printf("\n4: Preorder traversal and display\n");
        printf("\n5: Largest in BST\n");
        printf("\n6: Smallest in BST\n");
        printf("\n7: Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            struct BST *temp = create();
            if (root == NULL)
            {
                root = temp;
            }
            else
            {
                insert(root, temp);
            }
            break;
        }

        case 2:
        {
            inorder(root);
            break;
        }
        case 3:
        {
            postorder(root);
            break;
        }
        case 4:
        {
            preorder(root);
            break;
        }
        case 5:
        {
            printf("Largest :%d", Largest(root));
            break;
        }
        case 6:
        {
            printf("Smallest :%d", Smallest(root));
            break;
        }
        case 7:
        {
            exit(0);
        }
        default:
        {
            printf("\n Error!! Try Again");
        }
        }
    }
}