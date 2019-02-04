#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int hobbies[1010];

bool cmp(vector<int> v1,vector<int> v2)
{
    return v1[0]<v2[0];
}

bool outcmp(int a,int b)
{
    return a>b;
}

int GetCluster(vector<int> person)
{
    int cluster=-1;
    for(int i=0;i<person.size();i++)
    {
        if(hobbies[person[i]]!=0)
        {
            cluster = hobbies[person[i]]; //错误：如果一个人可以联系两个集合，则只考虑了一个
            break;
        }
    }
    if(cluster!=-1)
    {
        for(int i=0;i<person.size();i++)
        {
            hobbies[person[i]] = cluster;
        }
    }
    return cluster;
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<vector<int> > people;
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d:",&m);
        vector<int> v;
        for(int j=0;j<m;j++)
        {
            int temp;
            scanf("%d",&temp);
            v.push_back(temp);
        }
        people.push_back(v);
    }
    for(int i=0;i<people.size();i++)
        sort(people[i].begin(),people[i].end());
    sort(people.begin(),people.end(),cmp);
    vector<int> clusterContain;
    clusterContain.push_back(0); //第0个用占位
    int cluster_num = 0;
    for(int i=0;i<n;i++)
    {
        int cluster = GetCluster(people[i]);
        if(cluster == -1) //不属于现有cluster
        {
            clusterContain.push_back(0);
            clusterContain.back()++;
            cluster_num++; //cluster从1开始编号
            for(int k=0;k<people[i].size();k++)
                hobbies[people[i][k]] = cluster_num;
        }
        else
            clusterContain[cluster]++;
    }
    printf("%d\n",clusterContain.size()-1);
    sort(clusterContain.begin(),clusterContain.end(),outcmp);
    clusterContain.pop_back();
    for(int i=0;i<clusterContain.size();i++)
    {
        if(i) printf(" ");
        printf("%d",clusterContain[i]);
    }
}