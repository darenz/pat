#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

const int INF = 0x3fffffff;
const int MAXV = 1015;  //注意包涵了房屋和加油站总和
const int MAXM = 15;

int n,nv;

int graph[MAXV][MAXV];
int mdistance[MAXM][MAXV];  // G1->Gm，存储最短路径
int serviceRange;
double shortest[MAXM];
double longest[MAXM];
double average[MAXM];

int string2int(string s)
{
    int num = 0;
    if(s[0] == 'G')
    {
        for(int i=1;i<s.size();i++) 
            num = num*10 + s[i] - '0';
        return n+num;
    }
    else
    {
        for(int i=0;i<s.size();i++)
            num = num*10 + s[i] - '0';
        return num;
    }
}

bool visited[MAXV];
void Dijikstra(int start)
{
    int index = start - n;// 注意
    fill(&(mdistance[index][0]),&(mdistance[index][0])+MAXV,INF);
    fill(visited,visited+MAXV,false);
    mdistance[index][start] = 0;
    for(int i=1;i<=nv;i++)
    {
        int min=INF,min_n=-1;
        for(int j=1;j<=nv;j++)
        {
            if(visited[j]==false && mdistance[index][j]<min)
            {
                min = mdistance[index][j];
                min_n = j;
            }
        }
        if(min_n == -1)
            return ;
        visited[min_n] = true;
        for(int v=1;v<=nv;v++)
        {
            if(visited[v]==false && graph[min_n][v]+mdistance[index][min_n]<mdistance[index][v])
            {
                mdistance[index][v] = graph[min_n][v] + mdistance[index][min_n];
            }
        }
    }
}

bool cmp(int a,int b)
{
    if(shortest[a]!=shortest[b])
        return shortest[a]>shortest[b];
    if(average[a]!=average[b])
        return average[a]<average[b];
    if(a!=b)
        return a<b;
    return false;
}

int main()
{
    int m,k;
    scanf("%d%d%d%d",&n,&m,&k,&serviceRange);
    nv = n+m;
    fill(graph[0],graph[0]+MAXV*MAXV,INF);
    for(int i=0;i<k;i++)
    {
        int point1,point2; 
        char point1s[10],point2s[10];
        int len;
        scanf("%s%s%d",point1s,point2s,&len);
        point1 = string2int(point1s);
        point2 = string2int(point2s);
        if(point1==point2)
            continue;
        if(graph[point1][point2]<=len)
            continue;
        graph[point1][point2] = len;
        graph[point2][point1] = len;
    }
    for(int i=1;i<=m;i++)
    {
        Dijikstra(n+i);
        double total_t=0,shortest_t=INF,longest_t=-1;
        for(int j=1;j<=n;j++)
        {
            total_t += mdistance[i][j];
            if(mdistance[i][j]>longest_t)
                longest_t = mdistance[i][j];
            if(mdistance[i][j]<shortest_t)
                shortest_t = mdistance[i][j];
        }
        average[i] = total_t/n;
        shortest[i] = shortest_t;
        longest[i] = longest_t; 
    }
    int index[m+1];
    for(int i=1;i<=m;i++)
        index[i] = i;
    sort(index+1,index+m+1,cmp);
    int i=1;
    for(;i<=m;i++) //注意依次往后面找
    {
        if(longest[index[i]]<=serviceRange)
            break;
    }
    if(i>m)
        printf("No Solution");
    else
    {
        printf("G%d\n",index[i]);
        printf("%.1lf %.1lf",shortest[index[i]],average[index[i]]);
    }
}
