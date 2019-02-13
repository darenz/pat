//bullshit
#include<iostream>
#include<string>
#include<cmath>
#include<limits.h>
using namespace std;

typedef long long LL;

LL string2LL(string s)
{
    LL result=0;
    for(int i=0;i<s.size();i++)
    {
        result = result*10+(s[i]-'0');
    }
    return result;
}

int getLen(LL n)
{
    int len=0;
    while(n)
    {
        n /= 10;
        len++;
    }
    return len;
}

int main()
{
    string n;
    cin>>n;
    int len = n.size();
    int len1 = len/2;
    int len2 = len - len1;
    char n1[len1]={0};
    char n2[len2]={0};
    int i;
    for(i=0;i<len1;i++)
        n1[i] = n[i];
    for(;i<len;i++)
        n2[i-len1] = n[i];
    LL upper,lower;
    
    upper = string2LL(n1);
    lower = string2LL(n2);
    LL d_lower =0 ;
    d_lower = lower*2;
    int carry = 0;
    int len_l = getLen(lower);
    int len_dl = getLen(d_lower);
    if(len_dl>len_l)
        carry = 1;
    LL d_upper = upper*2+carry;
    int len_u = getLen(upper);
    int len_du = getLen(d_upper);

    int flag = 0;
    if(len_du+len_l==len)
    {
        int map1[10]={};
        for(int i=0;i<len;i++)
            map1[n[i]-'0']++;
        int map2[10]={};
        LL d_lower_t = d_lower;
        for(int i=0;i<len_l;i++) //如果有进位，忽略最高位
        {
            int a = d_lower_t%10;
            d_lower_t /= 10;
            map2[a]++; 
        }
        LL d_upper_t = d_upper;
        for(int i=0;i<len_du;i++)
        {
            int a = d_upper_t%10;
            d_upper_t /= 10;
            map2[a]++;
        }
        for(int i=0;i<10;i++)
        {
            if(map1[i]!=map2[i])
                break;
        }
        if(i==10)
            flag = 1;
    }
    if(flag==1)
        cout<<"Yes"<<endl;
    else 
        cout<<"No"<<endl;
    cout<<d_upper;
    if(carry==1)
        d_lower = d_lower - pow(10,(len_dl-1));
    cout<<d_lower<<endl;
    return 0;
}