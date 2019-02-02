#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    set<char> losKeyset;
    set<char>::iterator setit;
    vector<char> lossKeyv;
    char originalInput[100];
    char realOutput[100];
    scanf("%s %s",originalInput,realOutput);
    int ol = strlen(originalInput);
    int rl = strlen(realOutput);
    int i=0,j=0;

    //边界条件考虑周全.最后一个输出之后的所有输入都是缺失，不能立即退出
    //j<=rl是侥幸可用。j=r1时已溢出，当然全部失配
    //应将realOutput最后一个元素设为 #或其他
    while(i<ol && j<=rl)
    {
        char ok = islower(originalInput[i])?toupper(originalInput[i]):originalInput[i];
        char rk = islower(realOutput[j])?toupper(realOutput[j]):realOutput[j];
        if(ok!=rk)
        {
            setit = losKeyset.find(ok);
            if(setit==losKeyset.end())
            {
                losKeyset.insert(ok);
                lossKeyv.push_back(ok);
            }
        }
        else
            j++;
        i++;
    }
    for(int i=0;i<lossKeyv.size();i++)
        printf("%c",lossKeyv[i]);

    return 0;
}
