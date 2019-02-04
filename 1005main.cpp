#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int main()
{
    char input[110];
    scanf("%s",input);
    int len = strlen(input);
    int sum = 0 ;
    for(int i=0;i<len;i++)
        sum += input[i] - '0';

    string number_str[10]=
    {
        "zero","one","two","three","four","five","six","seven","eight","nine"
    };

    vector<string> output;
    if(sum == 0)
        cout<<"zero";
    while(sum)
    {
        output.push_back( number_str[sum%10] );
        sum /= 10;
    }
    int count_space = output.size()-1;
    for(int i=output.size()-1;i>=0;i--)
    {
        cout<<output[i];
        if(count_space--)
            cout<<" ";
    }
    return 0;
}
