#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct student
{
    char name[15];
    char id[15];
    int grade;
} student;

bool cmp(student a,student b)
{
    return a.grade>b.grade;
}

int main()
{
    int n;
    scanf("%d",&n);
    student sts[n];
    for(int i=0;i<n;i++)
        scanf("%s %s %d",sts[i].name,sts[i].id,&sts[i].grade);
    int low,high;
    scanf("%d %d",&low,&high);
    if(low>high)
        return 0;
    sort(sts,sts+n,cmp);
    int i=0;
    int j;
    while(i<n && sts[i].grade>high) i++;
    j = i;
    while(j<n && sts[j].grade>=low) j++;
    j--;
    if(j<i)
        printf("NONE\n");
    else
    {
        for(int k=i;k<j+1;k++)
            printf("%s %s\n",sts[k].name,sts[k].id);
    }

    return 0;
}
