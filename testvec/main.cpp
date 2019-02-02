#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct test
{
    vector<int> v;

} test;

bool cmp();

int main()
{
    test t[10];
    cout<<sizeof(t[0])<<endl;
    cout<<sizeof(t[0].v)<<endl;
    for(int i=0;i<100;i++)
    {
        t[0].v.push_back(i);
        t[1].v.push_back(i);
    }
    cout<<t[0].v.size()<<endl;
    cout<<t[0].v.capacity()<<endl;
    cout<<t[1].v[0]<<endl;
    return 0;
}
