#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int graph[1010][1010];
int L;
int n;

int crr_count;
bool visited[1010];
void DFS(int index,int depth)
{
    if(depth>L+1)
        return;
    visited[index] = true;
    crr_count++; //输出时减一，减自己
    for(int i=1;i<=n;i++)
    {
        if(i!=index && graph[index][i]==1 && visited[i]==false)
            DFS(i,depth+1);
    }
}

void BFS(int index)
{
    int depth = 0;
    crr_count = 0;
    queue<pair<int,int> > q; //index,depth
    q.push(pair<int,int>(index,0));
    while(!q.empty())
    {
        pair<int,int> top = q.front();
        q.pop();
        // visited[top.first] = true;
        if(top.second>L)
            return;
        crr_count++;
        for(int i=1;i<=n;i++)
        {
            if(i!=index && graph[top.first][i]==1 && visited[i]==false)
            {
                visited[i] = true;
                q.push(pair<int,int>(i,top.second+1));
            }
        }
    }
}

int CountDirect(int index)
{
    int count = 0;
    for(int i=1;i<=n;i++)
    {
        if(i!=index && graph[index][i]==1) 
            count++;
    }
    return count;
}

int main()
{
    scanf("%d%d",&n,&L);
    for(int i=1;i<=n;i++)
    {
        int follow_n;
        scanf("%d",&follow_n);
        for(int j=0;j<follow_n;j++)
        {
            int follow;
            scanf("%d",&follow);
            graph[follow][i] = 1;
        }
    }
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        int query_index;
        scanf("%d",&query_index);
        int direct_followers = CountDirect(query_index);
        fill(visited,visited+n+1,0);
        crr_count=0;
        // DFS(query_index,0);
        BFS(query_index);
        printf("%d\n",crr_count-1);
    }
}