#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct node
{
    int weight;
    vector<node*> childs;
} node;

node nds[110];
vector<vector<node*> > results;
int s;
int crr_sum;
vector<node*> path;

void DFS(node *root)
{
    crr_sum += root->weight;
    path.push_back(root);
    if(crr_sum == s && root->childs.size()==0)
        results.push_back(path);
    if(crr_sum<s && root->childs.size()>0)
    {
        for(int i=0;i<root->childs.size();i++)
            DFS(root->childs[i]);
    }
    crr_sum -= root->weight;
    path.pop_back();
}

bool cmp(vector<node*> a,vector<node*> b)
{
    for(int i=0;i<a.size() && i<b.size();i++)
    {
        if(a[i]->weight!=b[i]->weight)
            return a[i]->weight > b[i]->weight;
    }
    return a.size()>b.size();
}

int main()
{
    int n,m;
    scanf("%d %d %d",&n,&m,&s);
    for(int i=0;i<n;i++)
        scanf("%d",&nds[i].weight);
    for(int i=0;i<m;i++)
    {
        int id,k;
        scanf("%d %d",&id,&k);
        for(int j=0;j<k;j++)
        {
            int child;
            scanf("%d",&child);
            nds[id].childs.push_back(&nds[child]);
        }
    }
    node* root = &nds[0];
    crr_sum = 0;
    DFS(root);
    sort(results.begin(),results.end(),cmp);
    for(int i=0;i<results.size();i++)
    {
        for(int j=0;j<results[i].size();j++)
        {
            printf("%d",results[i][j]->weight);
            if(j<results[i].size()-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}

