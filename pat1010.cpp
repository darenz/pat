#include <iostream>
#include "cstdio"
#include "string"
#include <limits.h>
using namespace std;

int getNum(char c)
{
    if(c>='0' && c<='9')
        return c-'0';
    else if (c>='a' && c<='z')
        return 10 + c - 'a';
    else
        return 0;
}

long long GetDec(string n,int radix)
{
    long long result = 0;
    for(int i=0;i<n.size();i++)
        result = result*radix + getNum(n[i]);
    return result;
}
/*
int main()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    cout<<GetDec(s,n);
}
*/
int main(int argc, char const *argv[]) {
    string n1,n2;
    cin>>n1>>n2;
    int tag;
    cin>>tag;
    int radix;
    cin>>radix;
    long long dec;
    if(tag == 2)
        swap(n1,n2);
    dec = GetDec(n1,radix);
    int k=0;
    long long another_dec=0;
    while(another_dec!=dec && k<INT_MAX)
        another_dec = GetDec(n2,++k);
    if(another_dec!=dec)
        cout<<"Impossible";
    else 
        cout<<k;
    return 0;
}
