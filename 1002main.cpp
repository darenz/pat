#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef struct Poly
{
    int N;
    float a;
} poly;

int main()
{
    int n1,n2;

    scanf("%d",&n1);
    poly a1[n1];
    for(int i=0;i<n1;i++)
        scanf("%d %f",&a1[i].N,&a1[i].a);

    scanf("%d",&n2);
    poly a2[n2];
    for(int i=0;i<n2;i++)
        scanf("%d %f",&a2[i].N,&a2[i].a);

    vector<poly> v_rt;
    int i=0,j=0;
    while(i<n1 && j<n2)
    {
        if(a1[i].N == a2[j].N)
        {
            poly t;
            t.N = a1[i].N;
            t.a = a1[i].a + a2[j].a;
            v_rt.push_back(t);
            i++; j++;
        }
        else if(a1[i].N > a2[j].N)
        {
            v_rt.push_back(a1[i]);
            i++;
        }
        else
        {
            v_rt.push_back(a2[j]);
            j++;
        }
    }
    if(i<n1)
    {
        for(;i<n1;i++)
            v_rt.push_back(a1[i]);
    }
    if(j<n2)
    {
        for(;j<n2;j++)
            v_rt.push_back(a2[j]);
    }
     //Î´¿¼ÂÇÌø¹ý0Ïî
    int nz_count = 0;
    for(int i=0;i<v_rt.size();i++)
    {
        if(v_rt[i].a != 0)
            nz_count++;
    }
    printf("%d",nz_count);
    for(int i=0;i<v_rt.size();i++)
    {
        if(v_rt[i].a != 0)
            printf(" %d %0.1f",v_rt[i].N,v_rt[i].a);
    }

    return 0;
}
