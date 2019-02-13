#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXV = 505;
const int INF = 0x37ffffff;

int capicity;
int n;
int G[MAXV][MAXV];
int bikes[MAXV];

int d[MAXV];
bool visited[MAXV];
vector<int> pre[MAXV];

void Dijkstra(int start)
{
    fill(d,d+n+1,INF);
    fill(visited,visited+n+1,false);
    d[start] = 0;
    for(int i=1;i<=n;i++)
    {
        int min_n=-1,min=INF;
        for(int j=0;j<=n;j++)
        {
            if(visited[j]==false && d[j]<min) //设置visited是必要的
            {
                min_n = j;
                min = d[j];
            }
        }
        if(min_n==-1)
            return;
        visited[min_n] = true;
        for(int v=1;v<=n;v++)
        {
            if(G[min_n][v]+d[min_n]<d[v])
            {
                d[v] = G[min_n][v] + d[min_n];
                // take[v] = bikes[min_n] + bikes[v] - capicity/2;
                pre[v].clear();
                pre[v].push_back(min_n);
            }
            else if(G[min_n][v]+d[min_n]==d[v])
            {
                pre[v].push_back(min_n);
            }
        }
    }
}

int length;
vector<int> result;
vector<int> path;
int min_out=INF,min_in=INF;

void DFS(int start,int dist)
{
    if(dist==start)
    {
        path.push_back(start);
        int bring=0,carry=0;
        for(int i=path.size()-2;i>=0;i--)
        {
            int need = capicity/2 - bikes[path[i]];
            if(need>0)
            {
                if(need-carry>0)
                {
                    bring += need-carry;
                    carry = 0;
                }
                else  //条件要考虑全
                    carry -= need;
            }
            else  
            {
                carry += abs(need);
            }
        }
        if(bring<min_out)
        {
            min_out = bring;
            min_in = carry;
            result.clear();
            result = path;
        }
        else if(bring==min_out && carry<min_in)
        {
            min_in = carry;
            result.clear();
            result = path;
        }
        path.pop_back(); //注意
        return;
    }
    path.push_back(dist);
    for(int i=0;i<pre[dist].size();i++)
    {
        DFS(start,pre[dist][i]);
    }
    path.pop_back();
}

int main()
{
    ios::sync_with_stdio(false);
    int sp,m;
    cin>>capicity>>n>>sp>>m;
    for(int i=1;i<=n;i++)
        cin>>bikes[i];

    fill(G[0],G[0]+MAXV*MAXV,INF);
    for(int i=0;i<m;i++)
    {
        int from,to,t;
        cin>>from>>to>>t;
        G[from][to] = t;
        G[to][from] = t;
    }
    Dijkstra(0);
    DFS(0,sp);

    cout<<min_out<<' ';
    for(int i=result.size()-1;i>=0;i--)
    {
        cout<<result[i];
        if(i)
            cout<<"->";
    }
    cout<<' '<<min_in;
    return 0;
}