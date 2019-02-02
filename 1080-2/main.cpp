#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef struct student
{
    student()
    {
        for(int i=0;i<6;i++)
            choices[i] = -1;
    }
    int gradeE,gradeI;
    int total;
    int choices[6];
    int id;
} student;

typedef struct school
{
    int need;
    int crrn;
    int last_rank;
    vector<int> accepted;
} school;
/*
int cmp(const void* a1,const void* b1)
{
    student* a=(student*)a1;
    student* b=(student*)b1;
    if(a->total!=b->total)
    {
        if(a->total>b->total)
            return -1;
        else
            return 1;
    }
    if(a->gradeE!=b->gradeE)
    {
        if(a->gradeE>b->gradeE)
            return -1;
        else
            return 1;
    }
    return 0;
}
*/
bool cmp(student a,student b)
{
    if(a.total!=b.total)
        return a.total>b.total;
    if(a.gradeE!=b.gradeE)
        return a.gradeE>b.gradeE;
    else
        return false;
}

int main()
{
    int N,M,k;
    scanf("%d %d %d",&N,&M,&k);
    student *sts = new student[N];
    school *schols = new school[M];
    for(int i=0;i<M;i++)
    {
        scanf("%d",&schols[i].need);
        schols[i].last_rank = -1;
        schols[i].crrn = 0;
    }
    for(int i=0;i<N;i++)
    {
        scanf("%d %d",&sts[i].gradeE,&sts[i].gradeI);
        sts[i].total = sts[i].gradeE+sts[i].gradeI;
        sts[i].id = i;
        for(int j=0;j<k;j++)
            scanf("%d",&sts[i].choices[j]);
    }
    //qsort(sts,N,sizeof(student),cmp);
    sort(sts,sts+N,cmp);
    int rank = 0;
    for(int i=0;i<N;i++)
    {
        int flag = 0;
        if(i>0 && sts[i].total==sts[i-1].total && sts[i].gradeE==sts[i-1].gradeE) ;
        else
            rank = i;
        for(int j=0;j<k;j++)
        {
            int choice = sts[i].choices[j];
            if(schols[choice].crrn<schols[choice].need
               || rank == schols[choice].last_rank )
            {
                schols[choice].accepted.push_back(sts[i].id);
                schols[choice].crrn++;
                if(schols[choice].crrn == schols[choice].need)
                    schols[choice].last_rank = rank;
                flag = 1;
            }
            if(flag)
                break;
        }
    }
    for(int i=0;i<M;i++)
    {
        sort(schols[i].accepted.begin(),schols[i].accepted.end());
        for(int j=0;j<schols[i].crrn;j++)
        {
            if(j) putchar(' '); //µ¥ÒýºÅ
            printf("%d",schols[i].accepted[j]);
        }
        puts("");
    }
    return 0;
}
