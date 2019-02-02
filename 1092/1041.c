#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int table[10010]={};
    int n;
    cin>>n;
    int bet;
    vector<int> possibleWin;
    vector<int>::iterator it;
    for(int i=0;i<n;i++)
    {
        cin>>bet;
        table[bet]++;
        if(table[bet]==1)
        {
            possibleWin.push_back(bet);
        }
        else
        {
            it = find(possibleWin.begin(),possibleWin.end(),bet);
            if(it!=possibleWin.end())
                possibleWin.erase(it);
        }
    }
    if(possibleWin.size()==0)
        cout<<"None";
    else
        cout<<possibleWin.begin();

    return 0;
}
