#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int cmp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int n,pay;
    scanf("%d %d",&n,&pay);
    int coins[n];
    for(int i=0;i<n;i++)
        scanf("%d",&coins[i]);
    qsort(coins,n,sizeof(int),cmp);

    for(int i=0;i<n;i++)
    {
        if(coins[i]>pay/2)  //可以取等号，注意
        {
            printf("No Solution");
            break;
        }
        int *pfind = lower_bound(coins,coins+n,pay-coins[i]);
        if(pfind!=coins+n && coins[i]+*pfind==pay && pfind!=&coins[i])
        {
            printf("%d %d",coins[i],*pfind);
            break;
        }
    }
    return 0;
}
