#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    string n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n.size();i++)
    {
        v.push_back(n[i]-'0');
    }
    int map1[10]={};
    int map2[10]={};
    for(int i=0;i<n.size();i++)
        map1[n[i]-'0']++;
    
    int carry=0;
    for(int i=v.size()-1;i>=0;i--)
    {
        v[i] = (v[i])*2+carry;
        carry = v[i]/10;
        v[i] = v[i]%10;
        map2[v[i]]++;
    }
    int i;
    for(i=0;i<10;i++)
    {
        if(map1[i]!=map2[i])
            break;
    }
    if(i==10)
        cout<<"Yes"<<endl;
    else
    {
        cout<<"No"<<endl;
    }
    if(carry) 
        cout<<carry;
    for(int i=0;i<v.size();i++)
        cout<<v[i];
    
}