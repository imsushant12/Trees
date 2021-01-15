//by Sushant Gaurav

#include <iostream>
#include <stdlib.h>
using namespace std;

//in place heap creation
void insert(int a[] , int n)
{
    int temp = a[n];
    int i = n;
    int parent = (i-1)/2;

    while(i>0 && temp > a[parent])
    {
        a[i] = a[parent];
        i = parent;
        parent = (i-1)/2;
    }
    a[i] = temp;
}

/*
OTHER WAY :
------------
void insert(int A[], int n)
{
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i % 2 == 0 ? (i/2)-1 : i/2]){
        A[i] = A[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    A[i] = temp;
}
*/

void createHeap(int a[] , int n)
{
    for(int i=1 ; i<n ; i++)
        insert(a , i);
}

void deleteHeap(int a[] , int n)
{
    int i=0 , j=0;
    int temp = a[n-1];
    a[i] = a[n-1];
    int lchild = 2*i+1;
    int rchild = 2*i+2;

    while((temp < a[lchild] || temp < a[rchild]))
    {
        if(a[lchild] > a[rchild])
            j = lchild;
        else
            j = rchild;

        if(j < n)
        {
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
        else
            break;

        temp = a[j];
        i = j;
        lchild = 2*i+1;
        rchild = 2*i+2;
    }
}

int main()
{
    int n,i,choice,data;
    int a[100];

    while(1)
    {
        cout<<endl;
        cout<<"1. To create heap"<<endl;
        cout<<"2. To insert an element"<<endl;
        cout<<"3. To delete element"<<endl;
        cout<<"4. To view the heap"<<endl;
        cout<<"5. EXIT"<<endl;
        cout<<"ENTER CHOICE : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            {
                cout<<"\nEnter the size of heap array : ";
                cin>>n;
                cout<<"\nEnter array : ";
                for(i=0 ; i<n ; i++)
                    cin>>a[i];
                createHeap(a , n);

                break;
            }

        case 2:
            {
                cout<<"\nEnter the element : ";
                cin>>data;
                a[n] = data;
                insert(a , n);
                n = n+1;

                break;
            }

        case 3:
            {
                deleteHeap(a , n);
                n= n-1;
                break;
            }

        case 4:
            {
                cout<<"\nHeap (level order-wise) : ";
                for(i=0 ; i<n ; i++)
                    cout<<a[i]<<"  ";
                cout<<endl;

                break;
            }
        case 5:
            {
                exit(0);
                break;
            }

        default:
            cout<<"\nINVALID CHOICE"<<endl;
        }
    }

    return 0;
}
