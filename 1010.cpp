#include <iostream>
#include <cstdio>
#include <string>
#include <limits.h>
#include <algorithm>
using namespace std;

int convert(char c)
{
    if(c>='0' && c<='9')
        return c-'0';
    if(c>='a' && c<='z')
        return 10+c-'a';
    return ' ';
}

long long getDec(string s,long long radix)
{
    long long result = 0;
    for(int i=0;i<s.size();i++)
    {
        int num=0;
        num = convert(s[i]);
        result = result*radix+num;
        if(result<0)
            return -1;
    }  
    return result;
}
 
long long doIt(long long dec1,string n2,long long lo,long long hi)
{
    if(lo>hi)
        return 0;
    long long mid = (lo+hi)/2;
    long long crr = getDec(n2,mid);
    if(crr==dec1)
        return mid;
    else if(dec1<crr || crr<0) // mid太大，crr转换超出longlong则crr<0
        return doIt(dec1,n2,lo,mid-1);
    else if(crr<dec1)
        return doIt(dec1,n2,mid+1,hi);   
    return 0;
}

int maxDigit(string n)
{
    int max=0;
    for(int i=0;i<n.size();i++)
    {
        int t = convert(n[i]);
        if(t>max)
            max = t;
    }
    return max;
}

int main()
{
    string n1,n2;
    int tag;
    long long radix;
    cin>>n1>>n2>>tag>>radix;
    if(tag==2)  
        swap(n1,n2);
    long long dec1 = getDec(n1,radix);
    long long lower = maxDigit(n2)+1;
    long long upper = max(lower,dec1)+1;
    //必须要设置下界
    //虽然当存在结果时查找可以成功，但是不存在结果时，可能会给出错误答案
    long long new_radix = doIt(dec1,n2,lower,upper); 
    if(new_radix == 0)
        cout<<"Impossible"<<endl;
    else 
        cout<<new_radix<<endl;
} 