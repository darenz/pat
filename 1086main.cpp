#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;
int preOrder[30];
int inOrder[30];

typedef struct node
{
    int data;
    struct node* left,*right;
} node;

node* CreateTree(int preLeft,int preRight,int inLeft,int inRight)
{

    //if(preLeft>preRight)
    if(inLeft>inRight)
        return NULL;
    node* root = new node;
    root->data = preOrder[preLeft];
    int i=0;
    for(;inOrder[i]!=preOrder[preLeft];i++);
    root->left = CreateTree(preLeft+1,preLeft+i-inLeft,inLeft,i-1);
    root->right = CreateTree(preLeft+i-inLeft+1,preRight,i+1,inRight);
    return root;
}

int count_space;
void PostOrder(node* root)
{
    if(root == NULL)
        return ;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data;
    if(count_space-->0)
        cout<<' ';
}

int main()
{
    string temp;
    int data;
    int n;
    stack<int> stk;
    int ipre=0,iin=0;
    cin>>n;
    count_space = n-1;
    for(int k=0;k<n*2;k++)
    {
        cin>>temp;
        if(temp=="Push")
        {
            cin>>data;
            stk.push(data);
            preOrder[ipre++] = data;
        }
        else
        {
            inOrder[iin++] = stk.top();
            stk.pop();
        }
    }
    node* root = CreateTree(0,n-1,0,n-1);
    PostOrder(root);

    return 0;
}
