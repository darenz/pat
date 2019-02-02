#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    /*
    char s[20];
    char c;
    int i=0;
    while(1)
    {
        c = getchar() ;
        if(c!='\n')
            s[i++] = c;
        else
            break;
    }
    return 0;
    */
/*
    vector<int> a;
    a.resize(10,-1);
    cout<<a.size()<<endl;
    cout<<a[5]<<endl;
*/
 /*   int a,b,c;
    char t;
    cin>>a>>t>>b>>t>>c;
    cout<<a<<b<<c<<endl;
    cout<<setw(2)<<setfill('0')<<a<<b<<c<<endl;

*/
/*
    map<string,int> mp;
    mp["xxx"] = 1;
    mp["xxx"] += 1;
    cout<<mp["xxx"]<<endl;
    */
    int a=10;
    char s[5];
    itoa(a,s,10);
    string ss = s;
    cout<<ss<<endl;

}
