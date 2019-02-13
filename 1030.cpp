#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int INF = 0x3fffffff;
const int MAXV = 505;
int G[MAXV][MAXV];
int C[MAXV][MAXV];
int n;

vector<int> resultPath;
vector<int> path;
int minLength = INF;
int resultCost = INF;
int crrLength;
int crrCost;
bool visited[MAXV];
void DFS(int start,int stop)
{
    if(stop == start)
    {
        path.push_back(start);
        if(crrLength<minLength)
        {
            minLength = crrLength;
            resultCost = crrCost;
            resultPath.clear();
            resultPath = path;
        }
        else if(crrLength==minLength && crrCost<resultCost)
        {
            resultCost = crrCost;
            resultPath.clear();
            resultPath = path;
        }
    }
    else 
    {
        visited[start] = true;
        path.push_back(start);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false && G[start][i]!=INF )
            {
                crrLength += G[start][i];
                crrCost += C[start][i];
                DFS(i,stop);
                crrLength -= G[start][i];
                crrCost -= C[start][i];
            }
        }
 
    }
    path.pop_back();
}

int main()
{
    ios::sync_with_stdio(false);
    int m,start,dist;
    cin>>n>>m>>start>>dist;
    fill(G[0],G[0]+MAXV*MAXV,INF);
    fill(C[0],C[0]+MAXV*MAXV,0);
    for(int i=0;i<m;i++)
    {
        int city1,city2,distance,cost;
        cin>>city1>>city2>>distance>>cost;
        G[city1][city2] = distance;
        G[city2][city1] = distance;
        C[city1][city2] = cost;
        C[city2][city1] = cost;
    }
    DFS(start,dist);
    for(int i=0;i<resultPath.size();i++)
    {
        cout<<resultPath[i]<<' ';
    }
    cout<<minLength<<' '<<resultCost;
}
