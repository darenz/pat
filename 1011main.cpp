#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    float board[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            scanf("%f",&board[i][j]);
    }

    char buy[3] = {'W','T','L'};
    float profit = 1;
    char buy_result[3]={};

    for(int i=0,j;i<3;i++)
    {
        int max_loc = 0;
        for(j=0;j<3;j++)
        {
            if( board[i][j] > board[i][max_loc])
                max_loc = j;
        }
        buy_result[i] = buy[max_loc];
        profit *= board[i][max_loc];
    }
    profit = (profit*0.65-1)*2;
    for(int i=0;i<3;i++)
        printf("%c ",buy_result[i]);
    printf("%.2f",profit);  //浮点数精度控制.n

    return 0;
}
