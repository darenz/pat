#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int data[1010];

typedef struct node
{
    int data;
    node *left,*right;
} node;

int GetRootIndex(int low,int hi)
{
    int count = hi-low+1;
    int layers = log(count)/log(2) + 1;
    int nlayer = pow(2,layers-1);
    int prelayers = nlayer-1;
    int index = (pow(2,layers)-2)/2;
    if(count-prelayers < nlayer/2)
        index -= nlayer/2 - (count-prelayers);
    return index;
}

node* CreateTree(int low,int hi)
{
    if(low>hi)
        return NULL;
    node* root = new node;
    int iroot = GetRootIndex(low,hi)+low;
    root->data = data[iroot];
    root->left = CreateTree(low,iroot-1);
    root->right = CreateTree(iroot+1,hi);
    return root;
}

void LayerOrder(node* root)
{
    vector<int> layer_order;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* top = q.front();
        q.pop();
        layer_order.push_back(top->data);
        if(top->left!=NULL)
            q.push(top->left);
        if(top->right!=NULL)
            q.push(top->right);
    }
    for(int i=0;i<layer_order.size();i++)
    {
        if(i) printf(" ");
        printf("%d",layer_order[i]);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&data[i]);
    sort(data,data+n);
    node* root = CreateTree(0,n-1);

    LayerOrder(root);

    return 0;
}

