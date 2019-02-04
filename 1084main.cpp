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

    //�߽�����������ȫ.���һ�����֮����������붼��ȱʧ�����������˳�
    //j<=rl�ǽ��ҿ��á�j=r1ʱ���������Ȼȫ��ʧ��
    //Ӧ��realOutput���һ��Ԫ����Ϊ #������
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
