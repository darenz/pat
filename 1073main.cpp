#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char num[10010];
    int expp = 0;
    char flag_a;
    scanf("%c%s",&flag_a,num);
    int n = strlen(num);
    int loc;
    for(loc=0;loc<n;loc++)
    {
        if(num[loc] == 'E')
            break;
    }
    char flag_e = num[loc+1];
    int i=loc+2;
    while(i<n)
        expp = expp*10 + num[i++] - '0';

    if(flag_a == '-')
        printf("%c",'-');

    if(flag_e == '+')
    {
        i = 0;
        printf("%c",num[i]);
        i = i+2;
        while(expp)
        {
            if(i>=loc)
                printf("0");
            else
                printf("%c",num[i++]);
            expp--;
        }
        if(i<loc)
        {
            printf(".");
            while(i<loc)
                printf("%c",num[i++]);
        }
    }
    else
    {
        printf("0.");
        expp--;
        while(expp--)
            printf("0");
        i=0;
        printf("%c",num[i]);
        i = i+2;
        while(i<loc)
            printf("%c",num[i++]);
    }


    return 0;
}
