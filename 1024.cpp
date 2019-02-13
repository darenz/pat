#include <iostream>
#include <vector>
#include <cstdio>
#include <limits.h>
using namespace std;

typedef long long LL;

bool isPalindromic(LL n)
{
    vector<int> v;
    while(n)
    {
        v.push_back(n%10);
        n /= 10;
    }
    int i,j;
    for(i=0,j=v.size()-1;i<=j;i++,j--)
    {
        if(v[i]!=v[j])
            break;
    }
    if(i<j)
        return false;
    else 
        return true;
}

LL reverse(LL n)
{
    LL result = 0;
    while(n)
    {
        int t = n%10;
        n /= 10;
        result = result*10 + t;
    }
    return result;
}

int main()
{
    LL n;
    int k;
    cin>>n>>k;
    int t = k;
    LL temp;
    while(k>=0 && !isPalindromic(n))
    {
        n += reverse(n);
        k--;
    }
    cout<<n<<endl;
    cout<<t-k<<endl; 
}