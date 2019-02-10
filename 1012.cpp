#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node
{
    vector<int> childs;
} node;

node graph[10010];
int g_allMaxDepth;
vector<int> g_maxIndexResult;

int g_crrMaxDepth;
bool visited[10010]={};
void DFS(int index,int depth)
{
    visited[index] = true;
    if(depth>g_crrMaxDepth)
        g_crrMaxDepth = depth;
    for(int i=0;i<graph[index].childs.size();i++)
    {
        if(visited[graph[index].childs[i]]==false)
            DFS(graph[index].childs[i],depth+1);
    }
    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int first,second;
        scanf("%d%d",&first,&second);
        graph[first].childs.push_back(second);
        graph[second].childs.push_back(first);
    }
    g_allMaxDepth = 0;
    for(int k=1;k<=n;k++)
    {
        int graphN=0;        //注意重新初始化
        g_crrMaxDepth = 0;
        fill(visited,visited+n+1,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[(k+i)%(n+1)] && (k+i)%(n+1)!=0) //注意是n+1取模，且要排除0
            {
                graphN++;
                DFS((k+i)%(n+1),1);
            }
        }
        if(graphN>1)
        {
            printf("Error: %d components",graphN);
            return 0;
        } 
        if(g_crrMaxDepth>g_allMaxDepth)
        {
            g_maxIndexResult.clear();
            g_allMaxDepth = g_crrMaxDepth;
            g_maxIndexResult.push_back(k);
        }
        else if(g_crrMaxDepth == g_allMaxDepth)
            g_maxIndexResult.push_back(k);
    }
    if(g_maxIndexResult.size()>1)
        sort(g_maxIndexResult.begin(),g_maxIndexResult.end());
    for(int i=0;i<g_maxIndexResult.size();i++)
    {
        printf("%d\n",g_maxIndexResult[i]);
    }
}