#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

int GetReverseDec(int n,int radix)
{
    vector<int> v;
    while(n)
    {
        int left = n/radix;
        int last = n%radix;
        v.push_back(last);
        n = left;
    }
    int convert = 0;
    for(int i=0;i<v.size();i++)
    {
        // cout<<v[i];
        convert = convert*radix+v[i];
    }
    // cout<<endl;
    return convert;
}

bool PrimeJudge(int number)
{
    if(number<=1) //质数判断，注意
        return false;
    for(int i=2;i<=(int)sqrt(number);i++)
    {
        if(number%i==0)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    while(true)
    {
        int n,d;
        cin>>n;
        if(n<0) 
            return 0;
        cin>>d;
        int convert = GetReverseDec(n,d);
        if(PrimeJudge(n) && PrimeJudge(convert))
            cout<<"Yes"<<endl;
        else
        {
            cout<<"No"<<endl;
        }
    }
}