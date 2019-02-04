#include <iostream>
#include <cmath>

using namespace std;

typedef struct node
{
    int data;
    int height;
    node* left;
    node* right;
    node():height(1),left(NULL),right(NULL){}
    node(int d):data(d),height(1),left(NULL),right(NULL){}
} node;

int GetHeight(node* root)
{
    if(root==NULL)
        return 0;
    return root->height;
}

int GetBalanceFactor(node* root)
{
    return GetHeight(root->left) - GetHeight(root->right);
}

void UpdateHeight(node* root)
{
    root->height = max(GetHeight(root->left),GetHeight(root->right))+1;
}

void R(node* &root)
{   //注意高度要变化
    node* pleft = root->left;
    root->left = pleft->right;
    pleft->right = root;
    root = pleft;
    UpdateHeight(root->right);  // 更新顺序不能换，先下后上
    UpdateHeight(root);
}

void L(node* &root)
{
    node* pright = root->right;
    root->right = pright->left;
    pright ->left = root;
    root = pright;
    UpdateHeight(root->left);
    UpdateHeight(root);
}

void insert(node* &root,int data)
{
    if(root==NULL)
    {
        root = new node(data);
        return;
    }
    if(data < root->data)
        insert(root->left,data);
    else
        insert(root->right,data);
    UpdateHeight(root);
    if(GetBalanceFactor(root)==2)
    {
        if(GetBalanceFactor(root->left) == 1)
            R(root);
        else// if(GetBalanceFactor(root->left) == -1)//
        {
            L(root->left);
            R(root);
        }
    }
    else if(GetBalanceFactor(root) == -2)
    {
        if(GetBalanceFactor(root->right) == -1)
            L(root);
        else //if(GetBalanceFactor(root->right) == 1)
        {
            R(root->right);
            L(root);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int data;
    node* root = NULL;

    for(int i=0;i<n;i++)
    {
        cin>>data;
        insert(root,data);
    }
    cout<<root->data;

    return 0;
}
