//by Sushant Gaurav

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *left,*right;
};

struct node* create()
{
    int data;
    struct node *tree;
    tree=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to be inserted or type -1 for no insertion");
    scanf("%d",&data);

    if(data==-1)
        return 0;

    tree->info=data;

    printf("\nEnter left child of %d",data);
    tree->left=create();

    printf("\nEnter right child of %d",data);
    tree->right=create();

    return tree;
};

void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->info);
        inorder(root->right);
    }
}

void postorder (struct node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->info);
    }
}

void main()
{
    int choice;
    struct node *root;
    while(1)
    {
        printf("\nEnter your choice");
        printf("\n1. for insertion");
        printf("\n2. for pre-order traversal");
        printf("\n3. for in-order traversal");
        printf("\n4. for post-order traversal");
        printf("\n5. to exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
                root=create();
                break;
        case 2:
                preorder(root);
                break;
        case 3:
                inorder(root);
                break;
        case 4:
                postorder(root);
                break;
        case 5:
                exit(1);
                break;
        default:
                printf("\nInvalid Choice\n");
        }
    }
}
