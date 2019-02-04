#include <iostream>
#include <cstdio>
#include <ctype.h>
#include <cmath>
#include <float.h>
#include <vector>

using namespace std;

typedef struct node
{
    double price;
    int amount;
    vector<node*> childs;
} node;

//数组可能很大又有递归的时候，放在堆里（注意看数据量位数）
node nds[100010];
int notRoot[100010];

double rate;
double total;

void DFS(node* root)
{
    if(root->childs.size()==0)
    {
        total += root->amount*root->price;
        return;
    }
    double newPrice = root->price*(rate/100+1);
    for(int i=0;i<root->childs.size();i++)
    {
        root->childs[i]->price = newPrice;
        DFS(root->childs[i]);
    }
}

int main()
{
    int n;
    double initPrice;
    scanf("%d %lf %lf",&n,&initPrice,&rate);
    //node nds[n];
    //int notRoot[n]={};
    for(int i=0;i<n;i++)
    {
        int k;
        scanf("%d",&k);
        if(k==0)
        {
            scanf("%d",&nds[i].amount);
        }
        else
        {
            for(int j=0;j<k;j++)
            {
                int child;
                scanf("%d",&child);
                notRoot[child] = 1;
                nds[i].childs.push_back(&nds[child]);
            }
        }
    }
    int iroot=0;
    while(notRoot[iroot]==1) iroot++;
    node* root = &nds[iroot];
    root->price = initPrice;
    total = 0;
    DFS(root);
    printf("%.1lf",total);
    return 0;
}
