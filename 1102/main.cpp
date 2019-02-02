#include <iostream>
#include <queue>


using namespace std;

typedef struct node
{
    int data;
    struct node *left,*right;
} node;

int space_count;

void LevelOrder(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* p = q.front();
        q.pop();
        if(p->left!=NULL)
            q.push(p->left);
        if(p->right!=NULL)
            q.push(p->right);
        cout<<p->data;
        if(space_count-->0)
            cout<<' ';
    }
    return;
}

node* invert(node* root)
{
    if(root==NULL)
        return NULL;
    root->left = invert(root->left);
    root->right = invert(root->right);
    node* p = root->left;
    root->left = root->right;
    root->right = p;
    return root;
}

void InOrder(node* root)
{
    if(root==NULL)
        return;
    InOrder(root->left);
    cout<<root->data;
    if(space_count-->0)
        cout<<' ';
    InOrder(root->right);
}

int main()
{
    int n;
    cin>>n;
    space_count = n-1;
    char NONE = '-';
    node nds[n];
    int is_child_flags[n]={};
    for(int i=0;i<n;i++)
    {
        nds[i].data = i;
        char child;
        cin>>child;
        if(child!=NONE)
        {
            nds[i].left = &nds[child-'0'];
            is_child_flags[child-'0'] = 1;
        }
        else
            nds[i].left = NULL;
        cin>>child;
        if(child!=NONE)
        {
            nds[i].right = &nds[child-'0'];
            is_child_flags[child-'0'] = 1;
        }
        else
            nds[i].right = NULL;
    }
    int iroot = 0;
    while(is_child_flags[iroot]!=0 && iroot<n) iroot++;
    if(iroot>=n) return -1;

    node* root = invert(&nds[iroot]);
    LevelOrder(&nds[iroot]);
    cout<<endl;
    space_count = n-1;
    InOrder(root);

    return 0;
}
