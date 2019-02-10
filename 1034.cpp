#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct node
{
    string name;
    vector<pair<pair<int,int>,bool> > childs; //index,time,visited
    node(string _name):name(_name){};
} node;

// node graph[15000];
vector<node> graph;
bool visited[15000];
int k;

int FindChild(node &a,int index);
int totalTime;
int headerIndex;
int maxTime;
int members_n;
void DFS(int index)
{
    visited[index] = true;
    members_n++;
    int crr_time=0;
    for(int i=0;i<graph[index].childs.size();i++)
    {
        crr_time+=graph[index].childs[i].first.second;
        if(graph[index].childs[i].second == false)
        {
            int nearIndex = graph[index].childs[i].first.first;
            int nodeIndexNear = FindChild(graph[nearIndex],index);
            graph[nearIndex].childs[nodeIndexNear].second = true;
            totalTime += graph[index].childs[i].first.second;
        }
    }
    if(crr_time>maxTime)
    {
        maxTime = crr_time;
        headerIndex = index;
    }
    for(int i=0;i<graph[index].childs.size();i++)
    {
        if(visited[graph[index].childs[i].first.first]==false)
        {
            DFS(graph[index].childs[i].first.first);
        }
    }
}

int FindPerson(string name )
{
    for(int i=0;i<graph.size();i++)
    {
        if(graph[i].name == name)
            return i;
    }
    return -1;
}

int FindChild(node &a,int index)
{
    for(int i=0;i<a.childs.size();i++)
    {
        if(a.childs[i].first.first==index)
            return i;
    }
    return -1;
}

bool cmp(pair<string,int> a,pair<string,int> b)
{
    return a.first<b.first;
}

int main()
{
    int n;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        char name_s[4] = {};
        scanf("%s",name_s);
        string name1 = name_s;
        scanf("%s",name_s);
        string name2 = name_s;
        int time;
        scanf("%d",&time);
        int index1 = FindPerson(name1);
        int index2 = FindPerson(name2);

        if(index1 == -1)
        {
            graph.push_back(node(name1));
            index1 = graph.size()-1;
        }
        if(index2 == -1)
        {
            graph.push_back(node(name2));
            index2 = graph.size()-1;
        }
        int child1 = FindChild(graph[index1],index2);
        int child2 = FindChild(graph[index2],index1);
        if(child1==-1)
            graph[index1].childs.push_back(pair<pair<int,int>,bool>(pair<int,int>(index2,time),false));
        else
        {
            graph[index1].childs[child1].first.second += time;
        }
        
        if(child2==-1)
            graph[index2].childs.push_back(pair<pair<int,int>,bool>(pair<int,int>(index1,time),false));
        else
        {
            graph[index2].childs[child2].first.second += time;
        }
    }
    vector<int> headers;
    vector<int> members;
    for(int i=0;i<graph.size();i++)
    {
        if(visited[i]==false) 
        {
            totalTime = 0;
            members_n = 0;
            maxTime = 0;
            DFS(i);
            if(totalTime>k && members_n>2)
            {
                headers.push_back(headerIndex);
                members.push_back(members_n);
            }
        }
    }
    vector<pair<string,int> > output;
    for(int i=0;i<headers.size();i++)
    {
        pair<string,int> temp;
        temp.first = graph[headers[i]].name;
        temp.second = members[i];
        output.push_back(temp);
    }
    sort(output.begin(),output.end(),cmp);
    printf("%d\n",output.size());
    for(int i=0;i<output.size();i++)
    {
        printf("%s %d\n",output[i].first.c_str(),output[i].second);
    }
}