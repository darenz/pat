#include <iostream>
#include <string>

using namespace std;

char origin[] = {'1','0','l','O'};
char target[] = {'@','%','L','o'};

int main()
{
    int n ;
    cin>>n;
    string in_name[n],in_psw[n];
    for(int i=0;i<n;i++)
        cin>>in_name[i]>>in_psw[i];

    int count=0;
    int flag[n]={};
    for(int i=0;i<n;i++)
    {
        int j=0;
        while(j<in_psw[i].size())
        {
            for(int k=0;k<4;k++)
            {
                if(in_psw[i][j] == origin[k])
                {
                    flag[i] = 1;
                    in_psw[i][j] = target[k];
                }
            }
            j++;
        }
    }
    for(int i=0;i<n;i++)
        count += flag[i];
    //Êä³ö
    if(count == 0 && n>1)
        cout<<"There are "<<n<<" accounts and no account is modified";
    else if(count==0 && n==1)
        cout<<"There is 1 account and no account is modified";
    else
    {
        cout<<count<<endl;
        int count_enter = count -1;
        for(int i=0;i<n;i++)
        {
            if(flag[i] == 1)
            {
                cout<<in_name[i]<<" "<<in_psw[i];
                if(count_enter--)
                    cout<<endl;
            }
        }
    }
    return 0;
}
