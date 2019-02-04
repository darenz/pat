#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int idata;
int data[1010];
int tree[1010];

void InOrder(int index)
{
    if(index>n)
        return;
    InOrder(index*2) ;
    tree[index] = data[idata++];
    InOrder(index*2+1);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>data[i];
    sort(data,data+n);
    InOrder(1);
    for(int i=0;i<n;i++)
    {
        if(i) cout<<" ";
        cout<<tree[i+1];
    }
    return 0;
}

