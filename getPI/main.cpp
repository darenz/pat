#include <iostream>
#include <cmath>

using namespace std;
#define MAXN 100000
double x[MAXN];

int main()
{
    double a = 0;
    for(int i=0;i<MAXN;i++)
    {
        x[i] = a/(MAXN/2);
        a++;
       // cout<<x[i];
    }
    double ct = 0;
    for(int i=0;i<MAXN;i++)
    {
        for(int j=0;j<MAXN;j++)
        {
            if(pow(x[i]-1,2)+pow(x[j]-1,2)<1)
                ct++;
        }
    }
    cout<<ct/(MAXN*MAXN)*4<<endl;

    return 0;
}
