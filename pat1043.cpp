#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

typedef struct node
{
    int data;
    node* left;
    node* right;
    node(int a):data(a),left(NULL),right(NULL){}
} node;

void insert(node* &root,int a)
{
    if(root==NULL)
        root = new node(a);
    else if(a<root->data)
        insert(root->left,a);
    else 
        insert(root->right,a);
    return;

}

int pOrder[1010];
int prei;

void PreOrder(node* root)
{
    if(root==NULL)
        return;
    pOrder[prei] = root->data; 
    prei++;
    PreOrder(root->left);
    PreOrder(root->right);
}

int pOrder2[1010];
int prei2;
void PreOrder2(node* root)
{
    if(root==NULL)
        return;
    pOrder2[prei2] = root->data; 
    prei2++;
    PreOrder2(root->right);
    PreOrder2(root->left);
}

int pstOrder[1010];
int psti;
void PostOrder(node* root)
{
    if(root==NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    pstOrder[psti++] = root->data;
}

int pstOrder2[1010];
int psti2;
void PostOrder2(node* root)
{
    if(root==NULL)
        return;
    PostOrder2(root->right);
    PostOrder2(root->left);
    pstOrder2[psti2++] = root->data;
}

int main()
{
    int n;
    scanf("%d",&n);
    int data[n];
    for(int i=0;i<n;i++)
        scanf("%d",&data[i]);
    node* root = new node(data[0]);
    for(int i=1;i<n;i++)
        insert(root,data[i]);

    PreOrder(root);
    PreOrder2(root);
//    for(int i=0;i<n;i++)
//        printf("%d ",pOrder[i]);
//    printf("\n");
//
//    for(int i=0;i<n;i++)
//        printf("%d ",pOrder2[i]);
//    printf("\n");
//
    bool flag1=true;
    bool flag2=true;
    for(int i=0;i<n;i++)
    {
        if(pOrder[i]!=data[i] )
        {
            flag1 = false;
        }
        if(pOrder2[i]!=data[i])
        {
            flag2 = false;
        }
        if(flag1==false && flag2==false)
        {
            printf("NO");
            return 0;
        }
    }
    if(flag1==false)
        PostOrder2(root);
    else 
        PostOrder(root);
    printf("YES\n");
    for(int i=0;i<n;i++)
    {
        if(i)
            printf(" ");
        if(flag1)
            printf("%d",pstOrder[i]);
        else
            printf("%d",pstOrder2[i]);
    }
    return 0;
}
