#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;
int H;

typedef struct man
{
    int talent;
    int virtue;
    long id;

    int flag ;
    int sum;
} man;

/*
bool cmp(man a,man b)
{
    if(a.talent >= H && a.virtue >=H)  //同圣人
    {
        if(b.talent>=H && b.virtue>=H)
        {
            if(a.talent+a.virtue != b.talent+b.virtue)
                return a.talent+a.virtue > b.talent+b.virtue;
            else if(a.virtue != b.virtue)
                return a.virtue > b.virtue;
            else
                return a.id < b.id;
        }
        else
            return true;
    }
    else if(b.talent>=H && b.virtue>=H) //
        return false;
    else if(a.virtue>=H)
    {
        if(b.virtue>=H) //同君子
        {
            if(a.talent+a.virtue != b.talent+b.virtue)
                return a.talent+a.virtue > b.talent+b.virtue;
            else if(a.virtue != b.virtue)
                return a.virtue > b.virtue;
            else
                return a.id < b.id;
        }
        else //
            return true ;
    }
    else if(b.virtue>=H) //
        return false;
    else if(a.virtue>=a.talent)
    {
        if(b.virtue>=b.talent) //同愚人
        {
            if(a.talent+a.virtue != b.talent+b.virtue)
                return a.talent+a.virtue > b.talent+b.virtue;
            else if(a.virtue != b.virtue)
                return a.virtue > b.virtue;
            else
                return a.id < b.id;
        }
        else
            return true;
    }
    else // 同小人
    {
        if(a.talent+a.virtue != b.talent+b.virtue)
            return a.talent+a.virtue > b.talent+b.virtue;
        else if(a.virtue != b.virtue)
            return a.virtue > b.virtue;
        else
            return a.id < b.id;
    }
}

*/

bool cmp(man a,man b)
{
    if(a.flag!=b.flag)
        return a.flag<b.flag;
    else if(a.sum!=b.sum)
        return a.sum>b.sum;
    else if(a.virtue!=b.virtue)
        return a.virtue>b.virtue;
    else if(a.id!=b.id)
        return a.id<b.id;
}

int main()
{
    ios::sync_with_stdio(false);

    long n; //注意计数变量的类型
    int L;
    //cin>>n>>L>>H;
    scanf("%ld %d %d",&n,&L,&H);
    if(n==0)
        return 0;

    man vman[100010];
    long size=0;
    man t;
    for(int i=0;i<n;i++)
    {
        //cin>>t.id>>t.virtue>>t.talent;
        scanf("%ld %d %d",&t.id,&t.virtue,&t.talent);
        if(t.talent>=L && t.virtue>=L)
        {
            if(t.virtue>=H && t.talent>=H)
                t.flag = 1;
            else if(t.virtue>=H)
                t.flag = 2;
            else if(t.virtue>=t.talent)
                t.flag = 3;
            else
                t.flag = 4;
            t.sum = t.virtue+t.talent;

            vman[size] = t;
            size++;
        }

    }
    sort(vman,vman+size,cmp);
    //cout<<size<<endl;
    printf("%ld\n",size);
    //long enter_count = size - 1 ;
    for(int i=0;i<size;i++)
    {
        //cout<<vman[i].id<<" "<<vman[i].virtue<<" "<<vman[i].talent;
        printf("%ld %d %d\n",vman[i].id,vman[i].virtue,vman[i].talent);
      //  if(enter_count-->0)
      //       printf("\n");
            //cout<<endl;
    }

    return 0;
}
