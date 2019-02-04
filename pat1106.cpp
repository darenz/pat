#include <iostream>
#include <cstdio>
#include <vector>
#include <float.h>

using namespace std;

typedef struct node
{
    double price;
    vector<node*> childs;
} node;

node nds[100000];
double rate;
double lowestPrice;
int lowestCount;

void DFS(node* root)
{
    if(root->childs.size()==0)    
    {
        if(root->price < lowestPrice)
        {
            lowestPrice = root->price;
            lowestCount = 1;
        }
        else if(root->price == lowestPrice)
            lowestCount++;
        return ;
    }
    double newPrice = root->price*(1+rate/100);
    for(int i=0;i<root->childs.size();i++)
    {
        root->childs[i]->price = newPrice;
        DFS(root->childs[i]);
    }
    return;
}

int main()
{
    int n;    
    double initPrice;
    scanf("%d %lf %lf",&n,&initPrice,&rate);
    int notroot[n] = {};
    for(int i=0;i<n;i++)
    {
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            int child;
            scanf("%d",&child);
            nds[i].childs.push_back(&nds[child]);
            notroot[child] = 1;  
        }
    }
    int iroot=0;
    while(notroot[iroot]==1) iroot++;
    node* root = &nds[iroot];
    root->price = initPrice;
    lowestPrice = DBL_MAX;
    lowestCount = 0;
    DFS(root);
    printf("%.4lf %d",lowestPrice,lowestCount);
    return 0;
}

