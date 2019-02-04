/*
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main1092()
{
    int table[150] = {};
    char source[1010];
    char target[1010];
    scanf("%s %s",source,target);
    int srclen = strlen(source);
    int tarlen = strlen(target);
    for(int i=0;i<srclen;i++)
        table[source[i]]++;
    int flag=0;
    int miss=0;
    for(int i=0;i<tarlen;i++)
    {
        if(--table[target[i]]<0) //注意自己模拟边界情况，<号不能后--
        {
            flag = 1;
            miss++;
        }
    }
    if(flag == 1)
        printf("No %d",miss);
    else
        printf("Yes %d",srclen-tarlen);

    return 0;
}
*/
