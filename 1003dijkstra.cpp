#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3fffffff;
const int MAXV = 500;

int men[MAXV];
int total_men[MAXV];
int num[MAXV];

int n,graph[MAXV][MAXV];
int d[MAXV];
bool visited[MAXV];

void Dijkstra(int start)
{
    fill(d,d+n,INF);
    fill(visited,visited+n,false);
    fill(num,num+n,0);
    fill(total_men,total_men+n,0);
    d[start] = 0;
    num[start] = 1;
    total_men[start] = men[start];
    for(int i=0;i<n;i++) //最多选择n次
    {
        //找到已发现,但未加入的节点中距离最小的
        int min_n=-1,min=INF;
        for(int i=0;i<n;i++) 
        {
            if(visited[i]==false && d[i]<min)
            {
                min_n = i;
                min = d[i];
            }
        }
        if(min_n == -1) //未找到，退出。说明不连通（若连通应在外循环自然推出）
            return;
        //扩展该节点
        visited[min_n] = true;
        //以该节点可达目标，发现和更新节点
        for(int i=0;i<n;i++)
        {
            if(graph[min_n][i]+min<d[i]) //已经visited的节点，在次判断一定不会成立，所以不用重复判断visited[i]==false
            {
                d[i] = graph[min_n][i]+min; //且已经包含原来未被发现d为INF节点，以及已发现但未visit的节点
                num[i] = num[min_n];
                total_men[i] = total_men[min_n] + men[i];
            }
            else if(graph[min_n][i]+min==d[i])
            {
                num[i] += num[min_n];
                if(total_men[min_n]+men[i]>total_men[i])
                    total_men[i] = total_men[min_n]+men[i];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int roads_n,start,dist;
    cin>>n>>roads_n>>start>>dist;
    for(int i=0;i<n;i++)
        cin>>men[i];
    fill(graph[0],graph[0]+MAXV*MAXV,INF);

    for(int i=0;i<roads_n;i++)
    {
        int from,to,distance;
        cin>>from>>to>>distance;
        graph[from][to] = distance;
        graph[to][from] = distance;
    }
    Dijkstra(start);
    int shortest_road = num[dist];
    int max_men = total_men[dist];
    cout<<shortest_road<<' '<<max_men;
}