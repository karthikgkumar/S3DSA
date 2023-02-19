#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node;

node *root = NULL;
int data;
node* preorder(node* root){return root;};
node* inorder(node* root){return root;};

node *createnode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
node *insert(node *root, int data)
{
    if (root == NULL)
    {
        root = createnode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void postorder(node *root)
{
    if (root == NULL)
    {
        printf("not");
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d \n", root->data);
    }
}
int findmin(node *root)
{
    if (root == NULL)
    {
        printf("Empty\n");
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    else
    {
        return findmin(root->left);
    }
}

node *delete (node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = delete (root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete (root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
            return root;
        }
        else if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            root = temp;
            return root;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            root = temp;
            return root;
        }
        else
        {
            int temp = findmin(root->right);
            root->data = temp;
            root->right = delete (root->right, temp);
            return root;
        }
    }
}



void main()
{
    int ch=1;
    
    while (ch < 6)
    {
        printf("Enter  choice \n 1.insert \n 2.preorder \n 3.postorder \n4.inorder \n 5.delete \n");
    scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        printf("enter data\n");
        scanf("%d",&data);
            root=insert(root, data);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            postorder(root);
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            root=delete (root, data);
            break;

        default:
            printf("wrong choice\n");
            break;
        }
    
    }
}