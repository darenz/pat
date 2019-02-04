#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct info
{
    double capicity;
    double price;
} info;

bool cmp(info a,info b)
{
    return a.price>b.price;
}

int main()
{
    int n,demand;
    scanf("%d %d",&n,&demand);
    info infomation[n];

    double temp;
    for(int i=0;i<n;i++)
        scanf("%lf",&infomation[i].capicity);
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&temp);
        infomation[i].price = temp/infomation[i].capicity;
    }
    sort(infomation,infomation+n,cmp);

    double profit=0;
    for(int i=0;demand>0 && i<n;i++)
    {
        if(infomation[i].capicity<=demand)
        {
            profit += infomation[i].capicity*infomation[i].price;
            demand -= infomation[i].capicity;
        }
        else
        {
            profit += demand*infomation[i].price;
            break;
        }
    }
    printf("%.2lf",profit);
    return 0;
}
