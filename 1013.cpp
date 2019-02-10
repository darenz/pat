#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 1010;
int graph[MAXN][MAXN],visited[MAXN],nodes_num; //遍历时只能在限定范围内，否则会认为范围之外的节点也属于图

void DFS(int crr)
{
    visited[crr] = 1;
    for(int i=1;i<=nodes_num;i++)
    {
        if(graph[crr][i]!=0 && visited[i]==0)
            DFS(i);
    }
}

int DFSTraverse()
{
    int graphNum = 0;
    for(int i=1;i<=nodes_num;i++)
    {
        if(visited[i] == 0)
        {
            graphNum++;
            DFS(i);
        }
    }
    return graphNum;
}

int main()
{
    int m,k;
    scanf("%d%d%d",&nodes_num,&m,&k);
    if(nodes_num==0) 
        return 0;
    if(nodes_num==1) // 特例
    {
        cout<<0<<endl;
        return 0;
    }

    for(int i=0;i<m;i++)
    {
        int a_city,b_city;
        scanf("%d%d",&a_city,&b_city);
        graph[a_city][b_city] = 1;
        graph[b_city][a_city] = 1;
    }
    for(int i=0;i<k;i++) 
    {
        int check;
        scanf("%d",&check);
        fill(visited,visited+(nodes_num+1),0);
        visited[check] = 1;
        int graphN = DFSTraverse() ;
        printf("%d\n",graphN-1);
    }
}
//int* RemoveCity(int city)
//{
//    int *temp = new int[nodes_num+1];
//    fill(temp,temp+(1+nodes_num),0);
//
//    for(int i=1;i<=nodes_num;i++)
//    {
//        if(graph[city][i]!=0)
//        {
//            graph[city][i] = 0;
//            graph[i][city] = 0;
//            temp[i] = 1;
//        }
//    }
//    return temp;
//}
//void RecoverCity(int city,int *temp)
//{
//    for(int i=1;i<=nodes_num;i++)
//    {
//        graph[city][i] = temp[i];
//        graph[i][city] = temp[i];
//    }
//}
//

