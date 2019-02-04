#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef struct sign_info
{
    char name[16];
    int hour_in;
    int minute_in;
    int second_in;

    int hour_out;
    int minute_out;
    int second_out;
} sign_info;

bool early_in(sign_info a,sign_info b)
{
    if(a.hour_in<b.hour_in)
        return true;
    if(a.hour_in==b.hour_in)
    {
        if(a.minute_in<b.minute_in)
            return true;
        if(a.minute_in == b.minute_in)
        {
            if(a.second_in<b.second_in)
                return true;
        }
    }
    return false;
}

bool late_out(sign_info a,sign_info b)
{
    if(a.hour_out>b.hour_out)
        return true;
    if(a.hour_out == b.hour_out)
    {
        if(a.minute_out>b.minute_out)
            return true;
        if(a.minute_out == b.minute_out)
        {
            if(a.second_out>b.second_out)
                return true;
        }
    }
    return false;
}

int main()
{
    int n;
    scanf("%d",&n);
    sign_info stu[n];
    for(int i=0;i<n;i++)
    {
        scanf("%s%d:%d:%d %d:%d:%d",&stu[i].name,&stu[i].hour_in,
              &stu[i].minute_in,&stu[i].second_in,&stu[i].hour_out,
              &stu[i].minute_out,&stu[i].second_out);
    }


    sort(stu,stu+n,early_in);
    printf("%s ",stu[0].name);
    sort(stu,stu+n,late_out);
    printf("%s",stu[0].name);

    return 0;
}
