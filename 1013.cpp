#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 1010;
int graph[MAXN][MAXN];
int visited[MAXN]; 

void DFS(int crr)
{
    visited[crr] = 1;
    for(int i=1;i<MAXN;i++)
    {
        if(graph[crr][i]!=0 && visited[i]==0)
            DFS(i);
    }
}

int DFSTraverse()
{
    int graphNum = 0;
    for(int i=1;i<MAXN;i++)
    {
        if(visited[i] == 0)
        {
            graphNum++;
            DFS(i);
        }
    }
    return graphNum;
}

int* RemoveCity(int city)
{
    int *temp = new int[MAXN];
    fill(temp,temp+sizeof(int)*MAXN,0);

    for(int i=1;i<MAXN;i++)
    {
        if(graph[city][i]!=0)
        {
            graph[city][i] = 0;
            graph[i][city] = 0;
            temp[i] = 1;
            visited[city] = 1;
        }
    }
    return temp;
}

void RecoverCity(int city,int *temp)
{
    for(int i=1;i<MAXN;i++)
    {
        graph[city][i] = temp[i];
        graph[i][city] = temp[i];
    }
}

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int a_city,b_city;
        scanf("%d%d",&a_city,&b_city);
        graph[a_city][b_city] = 1;
        graph[b_city][a_city] = 1;
    }
    int check[k];
    for(int i=0;i<k;i++)
        scanf("%d",&check[i]);
    int *temp = new int[MAXN];
    for(int i=0;i<k;i++) 
    {
        fill(visited,visited+sizeof(int)*MAXN,0);
        temp = RemoveCity(check[i]);
        int graphN = DFSTraverse() ;
        printf("%d\n",graphN-1);
        RecoverCity(check[i],temp);
    }
}