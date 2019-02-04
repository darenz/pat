#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int hobbies[1010];
int numbers[1010];

int FindAncestor(int hobbyn)
{
    if(hobbies[hobbyn] == 0)
    {
        hobbies[hobbyn] = hobbyn;
        return hobbyn;
    }
    if(hobbies[hobbyn]==hobbyn)
        return hobbyn;
    return FindAncestor(hobbies[hobbyn]);
}

void CombineCluster(int ancestor1,int ancestor2)
{
    if(ancestor1==ancestor2)
        return;
    hobbies[ancestor2] = ancestor1;
    numbers[ancestor1] += numbers[ancestor2];
    numbers[ancestor2] = 0;
}

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<vector<int> > people;
    for(int i=0;i<n;i++)
    {
        int m;
        vector<int> v;
        scanf("%d:",&m);
        int anc;
        for(int j=0;j<m;j++)
        {
            int hobby;
            scanf("%d",&hobby);
            v.push_back(hobby);
            if(j==0)
                anc = FindAncestor(hobby);
            else
                CombineCluster(anc,FindAncestor(v[j]));
        }
        numbers[anc]++;
    }
    sort(numbers+1,numbers+1010,cmp);
    int ct=0;
    for(int i=1;i<1010;i++)
    {
        if(numbers[i]!=0)
            ct++;
        else
            break;
    }
    printf("%d\n",ct);
    for(int i=0;i<ct;i++)
    {
        if(i) printf(" ");
        printf("%d",numbers[i+1]);
    }
    return 0;
}