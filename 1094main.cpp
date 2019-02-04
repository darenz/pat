#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

typedef struct node
{
    int level;
    vector<node*> childs;
} node;
node nds[105];

int maxLevel;
int maxN;

void LevelOrder(node* root)
{
    queue<node*> q;
    q.push(root);
    int preLevel = 0;
    int crrn=0;
    node* top = NULL;
    while(!q.empty())
    {
        top = q.front();
        q.pop();
        if(top->level!=preLevel)
        {
            if(crrn>maxN)
            {
                maxN = crrn;
                maxLevel = preLevel;
                preLevel = top->level;
            }
            crrn = 0;
        }
        crrn++;
        for(int i=0;i<top->childs.size();i++)
        {
            top->childs[i]->level = top->level+1;
            q.push(top->childs[i]);
        }
    }
    if(crrn>maxN)
    {
        maxN = crrn;
        maxLevel = top->level;
    }
    return;
}

int main()
{
    int n,p;
    cin>>n>>p;
    int haveP[n+1]={};
    for(int i=0;i<p;i++)
    {
        int pid,k;
        cin>>pid>>k;
        int child;
        for(int j=0;j<k;j++)
        {
            cin>>child;
            nds[pid].childs.push_back(&nds[child]);
            haveP[child] = 1;
        }
    }
    int iroot=1;
    while(haveP[iroot]!=0) iroot++;
    node* root = &nds[iroot];
    root->level = 1;
    LevelOrder(root);
    cout<<maxN<<' '<<maxLevel;

    return 0;
}
