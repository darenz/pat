#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef struct stu
{
    char id[7];
    int C,M,E;
    float A;
    int rankC,rankM,rankE;
} student;

bool cmpC(student a,student b)
{
    return a.C>b.C;
}

bool cmpM(student a,student b)
{
    return a.M>b.M;
}

bool cmpE(student a,student b)
{
    return a.E>b.E;
}

int getBest(student a)
{
    if(a.rankC<=a.rankE && a.rankC<=a.rankM)
    {
        printf("%d C\n",a.rankC+1);
        return 0;
    }

    if(a.rankM<a.rankC && a.rankM<=a.rankE)
    {
        printf("%d M\n",a.rankM+1);
        return 0;
    }

    if(a.rankE<a.rankC && a.rankE<a.rankM)
    {
        printf("%d E\n",a.rankE+1);
        return 0;
    }
    else
        printf("erro\n");
}

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    student stus[N];
    char qu[M][7];
    for(int i=0;i<N;i++)
    {
        scanf("%s %d %d %d",stus[i].id,&stus[i].C,&stus[i].M,&stus[i].E);
        stus[i].A = (stus[i].C+stus[i].M+stus[i].E)/3;
    }
    for(int i=0;i<M;i++)
    {
        scanf("%s",qu[i]);
    }

    sort(stus,stus+N,cmpC);
    for(int i=0;i<N;i++)
        stus[i].rankC = i;
    sort(stus,stus+N,cmpM);
    for(int i=0;i<N;i++)
        stus[i].rankM = i;
    sort(stus,stus+N,cmpE);
    for(int i=0;i<N;i++)
        stus[i].rankE = i;

    for(int i=0;i<M;i++)
    {
        int flag = 0;
        int j=0;
        while(j<N && 0!=strcmp(stus[j++].id,qu[i])) ;
        if(j<=N)
            getBest(stus[j]);
        else
            printf("N/A\n");
    }

    return 0;
}
