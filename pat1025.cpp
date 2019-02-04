#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct student
{
    char ID[15];
    int grade;
    int loc;
    int loc_rank;
    int full_rank;
} sts[30010];

bool cmp(struct student a,struct student b)
{
    if(a.grade!=b.grade)
        return a.grade>b.grade;
    else
        return strcmp(a.ID,b.ID)<0;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d",&N);
    rewind(stdin);
    int p=0;
    for(int i=0;i<N;i++)
    {
        int k;
        scanf("%d",&k) ;
        int start = p;
        for(int j=0;j<k;j++)
        {
            scanf("%s %d",sts[p].ID,&sts[p].grade);
            sts[p].loc = i+1;
            p++;
        }
        sort(sts+start,sts+p,cmp);
        for(int j=start;j<p;j++)
        {
            if(j==start)
                sts[j].loc_rank = 1;
            else if(sts[j].grade == sts[j-1].grade)
                sts[j].loc_rank = sts[j-1].loc_rank;
            else 
                sts[j].loc_rank = j-start+1;
        }
    }

    sort(sts,sts+p,cmp);
    printf("%d\n",p);
    for(int i=0;i<p;i++)
    {
        if(i==0)
            sts[i].full_rank = 1;
        else if(sts[i].grade == sts[i-1].grade)
            sts[i].full_rank = sts[i-1].full_rank;
        else
            sts[i].full_rank = i+1;
        printf("%s %d %d %d\n",sts[i].ID,sts[i].full_rank,sts[i].loc,sts[i].loc_rank);
    }
    return 0;
}
