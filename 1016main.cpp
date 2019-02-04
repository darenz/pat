#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
#define ONLINE 1
#define OFFLINE 0

typedef struct Record
{
    char name[21];
    int month,day,hour,minute;
    int flag;
} Record;

int main()
{
    int rate[24];
    int N=0;
    for(int i=0;i<24;i++)
        scanf("%d",&rate[i]);

    scanf("%d",&N);
    Record records[N];
    /*
    char action[10];
    for(int i=0;i<N;i++)
    {
        scanf("%s %d:%d:%d:%d %s",records[i].name,&records[i].month,&records[i].day,&records[i].hour,&records[i].minute,action);
        if(strcmp(action,"on-line")==0)
            records[i].flag = ONLINE;
        else
            records[i].flag = OFFLINE;
    }
    */

    return 0;
}
