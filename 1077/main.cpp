#include <iostream>
#include <cstdio>
#include <cstring>


using namespace std;

int main()
{
    int n;
    if(n < 2)
        return 0;
    char c;
    scanf("%d",&n);
    getchar();
    char sentence[n][257];

    int minLen = 300;
    int index[n] = {};

    for(int i=0;i<n;i++)
    {
        cin.getline(sentence[i],257); //用该方法读入一行到char 数组
        int len = strlen(sentence[i]);
        index[i] = len-1;
        if(len<minLen)
            minLen = len;
    }
    if(minLen == 0)
        return 0;

    int flag = 0;
    for(int i=0;i<minLen;i++)
    {
        char c = sentence[0][index[0]];
        for(int j=1;j<n;j++)
        {
            if(sentence[j][index[j]--] != c)
            {
                flag = 1;
                break;
                int a;
            }
        }
        if(flag == 1)
            break;
        index[0]--;
    }

    char common_s[258] = {};
    strcpy(common_s,&(sentence[0][index[0]+1]));
    if(strlen(common_s) == 0)
        printf("nai");
    else
        printf("%s",common_s);

    return 0;
}
