//by Sushant Gaurav

#include <bits/stdc++.h>
using namespace std;

struct treenode
{
    int info;
    int ltag;
    int rtag;
    struct treenode *left;
    struct treenode *right;
};
struct treenode *dummy = new treenode;

//1-----------------------------------------------------------------------------------------------------------------------------

struct treenode* create(int data)
{
    struct treenode *newnode = new treenode;
    newnode->info = data;
    newnode->left = NULL;           //initially both left and right pointer points to NULL
    newnode->right = NULL;
    newnode->ltag = 0;              //initially both ltag and rtag are 0
    newnode->rtag = 0;
    return newnode;
}

struct treenode* insertion(struct treenode *root , struct treenode *newnode)
{
    if(root == NULL)                //as root is null so the inserted node will be the first node or the root node
    {
        root = newnode;             //newly inserted node will become first node or the root node

        dummy->left = root;         //dummy node's left always points the root node
        dummy->right = dummy;      //dummy node's right always points itself
        dummy->ltag = 1;            //both ltag and rtag are 1 for dummy node (it is pointing a child i.e. root)
        dummy->rtag = 1;
        dummy->info = INT_MAX;         //any random value can be assigned

        root->left = dummy;         //it is the first node so both left and right will point the dummy node
        root->right = dummy;

        return root;
    }

    //when already a tree a present
    else
    {
        if(newnode->info < root->info)        //using the property of BST for deciding the position of new node
        {
            newnode->left = root->left;
            root->left = newnode;
            newnode->right = root;
            root->ltag = 1;

            return root;
        }

        if(newnode->info > root->info)
        {
            newnode->right = root->right;
            root->right = newnode;
            newnode->left = root;
            root->rtag = 1;

            return root;
        }
    }
}



//2-----------------------------------------------------------------------------------------------------------------------------

void inorder(struct treenode *dummy)
{
    if(dummy == NULL)
        return;

    struct treenode *temp = dummy->left;

    while(temp != dummy)
    {
        while(temp->ltag == 1)      //first going to the left most node and then printing the node
            temp = temp->left;

        cout<<temp->info<<"  ";

        while(temp->rtag == 0)
        {
            temp = temp->right;
            if(temp == dummy)
                return;
            cout<<temp->info<<"  ";
        }
        temp = temp->right;
    }
}



int main()
{
    int data,choice;
    struct treenode *root = NULL;

    while(1)
    {
        cout<<"\n1. Create tree"<<endl;
        cout<<"2. In-order traversal"<<endl;
        cout<<"3. EXIT"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
                while(1)
                {
                    cout<<"Enter element or press -1 : ";
                    cin>>data;
                    if(data == -1)
                        break;
                    else
                    {
                        struct treenode *newnode;
                        newnode = create(data);
                        root = insertion(root , newnode);
                    }
                }
                break;
            }


        case 2:
            cout<<"\nIn-order traversal is : ";
            inorder(dummy);
            break;

        case 3:
            exit(0);
            break;

        default :
            cout<<"\nINVALID CHOICE"<<endl;
        }
    }
    return 0;

}
