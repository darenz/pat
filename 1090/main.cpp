#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef struct node
{
    double price;
    vector<node*> childs;
} node;
node nds[100000];

double rate;
double maxPrice;
int numMax;

void DFS(node *root)
{
    if(root->childs.size()==0)
    {
        if(root->price>maxPrice)
        {
            maxPrice = root->price;
            numMax = 1;
        }
        else if(root->price == maxPrice)
            numMax++;
        return;
    }
    double newPrice = root->price*(1+rate/100);
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
    int iroot=0;
    for(int i=0;i<n;i++)
    {
        int parent;
        scanf("%d",&parent);
        if(parent==-1)
            iroot = i;
        else
            nds[parent].childs.push_back(&nds[i]);
    }
    node* root = &nds[iroot];
    root->price = initPrice;
    DFS(root);
    printf("%.2lf %d",maxPrice,numMax);
    return 0;
}
