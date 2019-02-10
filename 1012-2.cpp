#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct course
{
    int index;
    int grade;
    int rank;
} course;

typedef struct student
{
    course crs[4];
    char name[10];
} student;

student sts[2010];

bool cmpCourse(course a,course b)
{
    if(a.rank!=b.rank)
        return a.rank<b.rank;
    return a.index<b.index;
}

int courseIndex_g;
int Partition(student *sts,int lo,int hi,int index)
{
    student pivot = sts[lo];
    while(lo<hi)
    {
        while(lo<hi && sts[hi].crs[index].grade<=pivot.crs[index].grade) hi--;
        sts[lo] = sts[hi];
        while(lo<hi && sts[lo].crs[index].grade>=pivot.crs[index].grade) lo++;
        sts[hi] = sts[lo];
    }
    sts[lo] = pivot;
    return lo;
}

void sortAll(student* sts,int lo,int hi,int index)
{
    if(lo>=hi)
        return;
    int pivot = Partition(sts,lo,hi,index);
    sortAll(sts,lo,pivot-1,index);
    sortAll(sts,pivot+1,hi,index);
}

char index2char(int index)
{
    switch (index)
    {
        case 1:
            return 'A';
        case 2:
            return 'C';
        case 3:
            return 'M';
        case 4:
            return 'E';
        default:
            break;
    }
    return '0';
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int C,M,E,A;
        scanf("%s%d%d%d",sts[i].name,&C,&M,&E);
        A = (C+M+E)/3;
        sts[i].crs[0].index = 1;
        sts[i].crs[0].grade = A;
        sts[i].crs[1].index = 2;
        sts[i].crs[1].grade = C;
        sts[i].crs[2].index = 3;
        sts[i].crs[2].grade = M;
        sts[i].crs[3].index = 4;
        sts[i].crs[3].grade = E;
    }
    for(courseIndex_g=0;courseIndex_g<4;courseIndex_g++)
    {
        sortAll(sts,0,n-1,courseIndex_g);
        sts[0].crs[courseIndex_g].rank = 1;
        for(int i=1;i<n;i++)
        {
            if(sts[i].crs[courseIndex_g].grade == sts[i-1].crs[courseIndex_g].grade)
                sts[i].crs[courseIndex_g].rank = sts[i-1].crs[courseIndex_g].rank;
            else 
                sts[i].crs[courseIndex_g].rank = i+1;
        }
    }
    for(int i=0;i<m;i++)
    {
        char query[10];
        scanf("%s",query);
        int j;
        for(j=0;j<n;j++)
        {
            if(strcmp(query,sts[j].name)==0)
                break;
        }
        if(j==n)
            printf("%s","N/A\n");
        else
        {
            sort(sts[j].crs,sts[j].crs+4,cmpCourse);
            printf("%d %c\n",sts[j].crs[0].rank,index2char(sts[j].crs[0].index));
        }
    }
}