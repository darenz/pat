//大数都要用vector比较保险
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef long long LL;

bool isPalindromic(vector<int> n)
{
    int i,j;
    for(i=0,j=n.size()-1;i<j;i++,j--)
    {
        if(n[i]!=n[j])
            break;
    }
    if(i<j)
        return false;
    else 
        return true;
}

vector<int> reverse(vector<int> v)
{
    vector<int> v2;
    int i,j;
    for(int i=v.size()-1;i>=0;i--)
        v2.push_back(v[i]);
    return v2;
}

void add(vector<int> &v1,vector<int> v2)
{
    int carry = 0;
    vector<int> v;
    for(int i=v2.size()-1;i>=0;i--)
    {
        int t = v1[i] + v2[i] + carry;
        v.push_back(t%10);
        carry = t/10;
    }
    if(carry==1)
        v.push_back(carry);
    v1 = v;
    v1 = reverse(v1);
}

int main()
{
    LL n;
    int k;
    cin>>n>>k;
    int t = k;
    vector<int> nv;
    while(n)
    {
        nv.push_back(n%10);
        n /= 10;
    }
    while(k>0 && !isPalindromic(nv))
    {
        add(nv,reverse(nv));
        k--;
    }
    for(int i=0;i<nv.size();i++)
        cout<<nv[i];
    cout<<endl;
    cout<<t-k<<endl;
}