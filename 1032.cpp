#include <iostream>
#include <cstdio>
#include <limits.h>
using namespace std;

const int MAX = 100010;

typedef struct node
{
    int address;
    char c;
    int next;
    int flag;
    node():flag(0){}
} node;
node mem[MAX];

int main()
{
    int head1,head2,n;
    cin>>head1>>head2>>n;
    for(int i=0;i<n;i++)
    {
        int addr,nxt;
        char c;
        cin>>addr>>c>>nxt;
        mem[addr].c = c;
        mem[addr].next = nxt;
    }
    int index = head1;
    while(index!=-1)
    {
        mem[index].flag = 1;
        int next = mem[index].next;
        index = next;
    }
    index = head2;
    while(index!=-1)
    {
        if(mem[index].flag==1)
        {
            printf("%05d",index); //注意输出格式！！！！！！！
            break;
        }
        int next = mem[index].next;
        index = next;
    }
    if(index==-1)
        cout<<-1;
}
