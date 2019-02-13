#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

typedef struct person
{
    int arrive;
    int process;
} person;

int convertToS(int h,int m,int s)
{
    return h*3600+m*60+s;
}

bool cmp(person a,person b)
{
    return a.arrive<b.arrive;
}

long total_wait;
queue<person> q;
person win[105];
bool occupied[105];

void checkWindows(int &clock_time,int k,vector<int> &empty)
{
    clock_time++;
    for(int i=0;i<k;i++)
    {
        if(occupied[i]==true)
        {
            win[i].process--;
            if(win[i].process==0)
            {
                occupied[i] = false;
            }
        }
        if(occupied[i]==false)
            empty.push_back(i);
   }
}

void selectNewPerson(int &clock_time,vector<int> &empty)
{
    int size = empty.size();
    for(int i=size-1;i>0;i--) // 1到最后一个
    {
        if(q.empty()) //服务完了
            return;
        person first = q.front();
        if(first.arrive>clock_time) //还没到时间
            return;
        q.pop();
        long wait = clock_time - first.arrive; //计算等待时间
        total_wait += wait;
        int win_n = empty[i]; //分配空窗
        win[win_n] = first; 
        occupied[win_n] = true;
        empty.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    vector<person> people;
    for(int i=0;i<n;i++)
    {
        person temp;
        int h,m,s,p;
        char c;
        cin>>h>>c>>m>>c>>s>>p;
        temp.process = p*60;
        temp.arrive = convertToS(h,m,s);
        if(temp.arrive>17*3600) //大于
            continue;
        people.push_back(temp);
    }
    sort(people.begin(),people.end(),cmp);
    for(int i=0;i<people.size();i++)
        q.push(people[i]);
    int served_n = q.size();

    vector<int> empty;
    empty.push_back(-1); //用-1占位，否则为空时vector会析构
    int clock_time = 8*3600-1;
    while(!q.empty())
    {
        checkWindows(clock_time,k,empty); //时间+1,返回空窗
        selectNewPerson(clock_time,empty); //选择新客户,同时计算其等待时间和总等待时间
    }
    double average_wait = ((double)total_wait)/((double)served_n)/60.0;
    printf("%.1lf",average_wait);
}