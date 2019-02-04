#include <iostream>
#include <cstdio>

using namespace std;

typedef struct node
{
    int data;
    int height;
    node *left,*right;
    node():height(1),left(NULL),right(NULL){}
} node;

int GetHeight(node* root)
{
    if(root == NULL)
        return 0;
    return root->height;
}

int GetBalanceFactor(node* root)
{
    return GetHeight(root->left) - GetHeight(root->right);
}

void R(node* &root)
{
    node* pleft = root->left;
    root->left = pleft->right;
    pleft->right = root;
    root = pleft;
}

void L(node* &root)
{
    node* pright = root->right;
    root->right = pright->left;
    pright->left = root;
    root = pright;
}

void UpdateHeight(node* root)
{
    root->height = GetHeight(root->left) - GetHeight(root->right);
}

void insert(node* &root,int data)
{
    if(root==NULL)
    {
        root = new node;
        root->data = data;
        return ;
    }
    if(data < root->data)
        insert(root->left,data);
    else 
        insert(root->right,data);
    UpdateHeight(root);
    if(GetBalanceFactor(root) == 2)
    {
        if(GetBalanceFactor(root->left) == 1)
            R(root);
        else if(GetBalanceFactor(root->left) == -1)
        {
            L(root->left);
            R(root);
        }
    }
    else if(GetBalanceFactor(root) == -2)
    {
        if(GetBalanceFactor(root->right) == -1)
            L(root);
        else if(GetBalanceFactor(root->right) == 1)
        {
            R(root->right);
            L(root);
        }
    }
}

void InOrder(node* root)
{
    if(root==NULL)
        return;
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

int main()
{
    int n;
    cin>>n;
    int data[n];
    node* root = NULL;
    for(int i=0;i<n;i++)
    {
        cin>>data[i];
        insert(root,data[i]) ;
    }
    InOrder(root);
    cout<<endl;
    return 0;
}

