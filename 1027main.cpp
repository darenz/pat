#include <iostream>
#include <cstdio>

using namespace std;

char num[3]={'A','B','C'};

char get13num(int n)
{
    if(n<10)
        return n+'0';
    else
        return num[n-10];
}

int main()
{
    int R1,G1,B1;

    scanf("%d %d %d",&R1,&G1,&B1);


    printf("#");
    printf("%c",get13num(R1/13));
    printf("%c",get13num(R1%13));
    printf("%c",get13num(G1/13));
    printf("%c",get13num(G1%13));
    printf("%c",get13num(B1/13));
    printf("%c",get13num(B1%13));

    return 0;
}
