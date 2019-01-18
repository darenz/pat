#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string cn[10] =
{"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

string sp[] =
{ "Qian","Bai","Shi"};

int flag_first = 1; //空格控制

string fuck  =  "why?everytime spend a long time to fix small problems?,fuck";
string fuck2 = "fuck the anti-viurs";
string fuck3 = "come on and fuck me";
string fuckyou;

void ReadFourDigits(int n)
{
    int num[4] = {};
    int i=0;
    while(n)
    {
        num[i++] = n%10;
        n/=10;
    }
    reverse(num,num+4);
    int pos_H_nz=0;
    int pos_L_nz=3;
    while(num[pos_H_nz]==0 && pos_H_nz<=3)
        pos_H_nz++;
    while(num[pos_L_nz]==0 && pos_L_nz>=0)
        pos_L_nz--;
    int count_z = 0;
    for(int i=0;i<4;i++)
    {
        if(num[i])
        {
            if(!flag_first)
                cout<<" ";
            else
                flag_first = !flag_first;

            cout<<cn[num[i]];
            if(i!=3)
                cout<<" "<<sp[i]; //个位要除开
        }
        else if(pos_H_nz<i && i<pos_L_nz)
        {
            if((count_z++)==0) // 中间多个0只读一个
                cout<<" "<<cn[0];
        }
    }
}

int main()
{
    long long numt,num;
    cin>>numt;
    if(numt == 0)  //单独处理0
        cout<<"ling";

    if(numt<0)
    {
        cout<<"Fu";
        flag_first = !flag_first;
    }
    num = abs(numt);
    if(num>=100000000)
    {
        if(!flag_first)
            cout<<" ";
        else
            flag_first = !flag_first;
        cout<<cn[num/100000000]<<" Yi";
    }
    num = num%100000000;
    int numL = num%10000;
    int numH = num/10000;
    int mai;
    ReadFourDigits(numH);
    if(numH) //高位为0的不读"万"
    {
        cout<<" Wan";
        if(numL<1000 && numL>0)
            cout<<" ling";
    }
    ReadFourDigits(numL);

    return 0;
}
