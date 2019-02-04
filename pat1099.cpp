#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct node
{
    int data;
    node *left,*right;
    node():left(NULL),right(NULL){}
} node;

int data[101];
int idata;

void InOrder(node* root)
{
    if(root==NULL)
        return;
    InOrder(root->left);
    root->data = data[idata++];
    InOrder(root->right);
}

void LevelOrder(node* root)
{
    int i=0;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* top = q.front();
        q.pop();
        if(top->left)
            q.push(top->left);
        if(top->right)
            q.push(top->right);
        if(i++) cout<<" ";
        cout<<top->data;
    }
}

int main()
{
    int n;
    cin>>n;
    node nds[n];
    for(int i=0;i<n;i++)
    {
        int leftIndex,rightIndex;
        cin>>leftIndex>>rightIndex;
        if(leftIndex!=-1)
            nds[i].left = &nds[leftIndex];
        if(rightIndex!=-1)
            nds[i].right = &nds[rightIndex];
    }
    for(int i=0;i<n;i++)
        cin>>data[i];
    sort(data,data+n);
    InOrder(&nds[0]);
    LevelOrder(&nds[0]);
    return 0;
}

