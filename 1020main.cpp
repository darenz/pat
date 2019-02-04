#include <iostream>
#include <deque>

using namespace std;

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} node;

#define MAXNODES 35
int postOrder[MAXNODES];
int inOrder[MAXNODES];
int n;

node* CreateTree(int postLeft,int postRight,int inLeft,int inRight)
{
    if(inLeft>inRight)
        return NULL;
    node* root = new node;
    root->data = postOrder[postRight];
    int posIn = inLeft;
    for(;inOrder[posIn]!=postOrder[postRight];posIn++) ;
/*    int posPost = postRight;

    for(;postOrder[posPost]!=inOrder[posIn+1];posPost--);
    root->left = CreateTree(postLeft,posPost-1,inLeft,posIn-1);
    root->right = CreateTree(posPost,postLeft-1,posIn+1,inRight);
*/
    root->left = CreateTree(postLeft,postLeft+(posIn-inLeft-1),inLeft,posIn-1);
    root->right = CreateTree(postLeft+(posIn-inLeft),postRight-1,posIn+1,inRight);
    return root;
}

void LevelOrder(node* root)
{
    deque<node*> q;
    q.push_back(root);
    int count_space = n-1;
    while(!q.empty())
    {
        node* pt = q.front();
        q.pop_front();
        if(pt->left)
            q.push_back(pt->left);
        if(pt->right)
            q.push_back(pt->right);
        cout<<pt->data;
        if(count_space-->0)
            cout<<' ';
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>postOrder[i];
    for(int i=0;i<n;i++)
        cin>>inOrder[i];

    node* root = CreateTree(0,n-1,0,n-1);
    LevelOrder(root);

    return 0;
}
