//by Sushant Gaurav

#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct treenode                                                                 //tree
{
    int info;
    struct treenode *left,*right;
};


struct treenode* create()
{
    int data;
    struct treenode *tree;
    tree=(struct treenode*) malloc (sizeof(struct treenode));
    printf("\nEnter data to be inserted or type -1 for no insertion : ");
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

void preorder(struct treenode *root)
{
    stack <treenode*> s;                                                    //tree node type stack

    while((root != NULL) || (!s.empty()))
    {
        if(root != NULL)
        {
            cout << root->info << " ";

            s.push(root);

            root = root->left;
        }
        else
        {
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
    cout<<endl;
}



void inorder(struct treenode *root)
{
    stack <treenode*> s2;                                                      //stack of tree-node type

    while((root != NULL) || (!s2.empty()))
    {
        if(root != NULL)
        {
            s2.push(root);
            root = root->left;
        }
        else
        {
            root = s2.top();
            s2.pop();
            cout << root->info << " ";
            root = root->right;
        }
    }
    cout<<endl;
}



void postorder(struct treenode *root)
{
    stack <treenode*> s3;

    struct treenode *previous = NULL;

    do
    {
        while(root != NULL)
        {
            s3.push(root);
            root = root->left;
        }

        while(root == NULL && (!s3.empty()))
        {
            root = s3.top();
            if(root->right == NULL || root->right == previous)
            {
                cout<<root->info<<" ";
                s3.pop();
                previous = root;
                root = NULL;

            }
            else
            {
                root = root->right;
            }
        }

    }while(!s3.empty());

    cout<<endl;

}

void levelorder(struct treenode *root)
{
    queue <treenode*> q;

    cout<<root->info<<" ";
    q.push(root);

    while(!q.empty())
    {
        root = q.front();
        q.pop();

        if(root->left)
        {
            cout<<root->left->info<<" ";
            q.push(root->left);
        }
        if(root->right)
        {
            cout<<root->right->info<<" ";
            q.push(root->right);
        }
    }

    cout<<endl;
}


int main()
{

    struct treenode *root;
    root=create();

    cout<<"\nPre-order is : ";
    preorder(root);

    cout<<"\nIn-order is : ";
    inorder(root);

    cout<<"\nPost-order is : ";
    postorder(root);

    cout<<"\nLevel-order is : ";
    levelorder(root);

    return 0;
}
