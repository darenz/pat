#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct student
{
    char ID[10];
    char name[10];
    int grade; 
} student;

bool cmpID(student& a,student& b)
{
    return strcmp(a.ID,b.ID)<0;
}

bool cmpName(student& a,student& b)
{
    if(strcmp(a.name,b.name)!=0)
        return strcmp(a.name,b.name)<0;
    else
        return cmpID(a,b);
}

bool cmpGrade(student& a,student& b)
{
    if(a.grade!=b.grade)
        return a.grade<b.grade;
    else
        return cmpID(a,b);
}

int main(int argc, char const *argv[])
{
    int N,C;
    scanf("%d %d",&N,&C);
    student stus[N];
    for(int i=0;i<N;i++)
    {
        scanf("%s %s %d",stus[i].ID,stus[i].name,&stus[i].grade);
    }
    switch(C)
    {
        case 1 :
            sort(stus,stus+N,cmpID);
            break;
        case 2 :
            sort(stus,stus+N,cmpName);
            break;
        case 3 :
            sort(stus,stus+N,cmpGrade);
            break;
        default:
            return 0;
    }
    for(int i=0;i<N;i++)
    {
        printf("%s %s %d\n",stus[i].ID,stus[i].name,stus[i].grade);
    }
    return 0;
}
