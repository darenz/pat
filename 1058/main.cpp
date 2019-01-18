#include <iostream>
#include <cstdio>

using namespace std;
//88.16.28 88.16.28
//out:177.16.27
int main()
{
    int a1,b1,c1;
    int a2,b2,c2;
    scanf("%d.%d.%d",&a1,&b1,&c1);
    scanf("%d.%d.%d",&a2,&b2,&c2);

    int a,b,c;
    int c_in;

    c = (c1+c2)%29;
    c_in = (c1+c2)/29;

    b = (c_in + b1 + b2)%17;
    c_in = (c_in + b1 + b2)/17;

    a = (c_in + a1 + a2);

    printf("%d.%d.%d",a,b,c);

    return 0;
}
