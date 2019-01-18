#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Poly
{
    int N;
    float a;
} Poly;

bool PolyCMP(Poly a,Poly b)
{//sort按照true的关系进行排序
    if(a.N > b.N)
        return true;
    else //要明确返回true,false
        return false;

    //return a.N>b.N
}

int main()
{
    int n1,n2;
    scanf("%d",&n1);
    Poly a1[n1];
    for(int i=0;i<n1;i++)
        scanf("%d %f",&a1[i].N,&a1[i].a);

    scanf("%d",&n2);
    Poly a2[n2];
    for(int i=0;i<n2;i++) //复制时要格外小心变量名更改
        scanf("%d %f",&a2[i].N,&a2[i].a);

    vector<Poly> v_rt;
    Poly t;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            t.N = a1[i].N + a2[j].N;
            t.a = a1[i].a * a2[j].a;
            v_rt.push_back(t);
        }
    }
    sort(v_rt.begin(),v_rt.end(),PolyCMP);

    int nz_count=0;
    int crt=0;
    int i=0;
    Poly t2 = {0,0};
    vector<Poly> v_rt2;
    while(i<v_rt.size())
    {
        t2.a = v_rt[i].a;
        t2.N = v_rt[i].N;

        while(v_rt[++i].N == v_rt[crt].N) //无论是否成立，i都自增
            t2.a += v_rt[i].a;
        //计算nz_count开始未考虑不能重复计算同次项
        if(t2.a)
        {
            nz_count++;
            v_rt2.push_back(t2);
        }
        crt = i; //更新crt
    }
    printf("%d",nz_count);
    for(int i=0;i<v_rt2.size();i++)
        printf(" %d %0.1f",v_rt2[i].N,v_rt2[i].a);

    return 0;
}
