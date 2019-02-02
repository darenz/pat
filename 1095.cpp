#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

typedef struct car
{
    char id[10];
    int ihh,imm,iss;
    int ohh,omm,oss;
} car;

typedef struct Record
{
    char id[10];
    int hh,mm,ss;
    int status;
} Record;

typedef struct query
{
    int hh,mm,ss;
} query;

bool cmpName(Record& a,Record& b)
{
    if(strcmp(a.id,b.id)<0)
}

int main()
{
    vector<Record> records;
    int n,k;
    scanf("%d %d",&n,&k);
    Record records[n];
    query[k];
    for(int i=0;i<n;i++)
    {
        char status[5];
        scanf("%s %d:%d:%d %s",records[i].id,&records[i].hh,&records[i].mm,&records[i].ss,status);
        if(strcmp(status,"in")==0)
            records[i].status = 1;
        else
            records[i].status = 0;
    }
    for(int i=0;i<k;i++)
        scanf("%d:%d:%d",&query[i].hh,&query[i].mm,&query[i].ss);
    sort(records,records+n,cmpName);
    Record* p1 = records;
    Record* p2 = p1+1;
    while(p2<records+n)
    {
        if(strcmp(p1->id,p2->id)==0)
        {
            if(p1->status==1 && )
        }
    }
}