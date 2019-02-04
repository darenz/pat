#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    string s="";
    string sinput;
    string check;
    getline(cin,sinput);
    getline(cin,check);
    int lenInput = sinput.length();
    int lenCheck = check.length();
    for(int i=0;i<lenInput;i++)
    {
        int flag=0;
        for(int j=0;j<lenCheck;j++)
        {
            if(check[j]==sinput[i])
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)
            s += sinput[i];
    }
    printf("%s",s.c_str());
    //system("pause");
    return 0;
}
