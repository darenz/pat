#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef struct time
{
    int hh,mm,ss;
} time;

typedef struct record
{
    string id;
    time t;
    int status;
} record;

bool cmpNameTime(record a,record b)
{
    if(a.id!=b.id)
        return a.id<b.id;
    if(a.t.hh!=b.t.hh)
        return a.t.hh<b.t.hh;
    if(a.t.mm!=b.t.mm)
        return a.t.mm<b.t.mm;
    if(a.t.ss!=b.t.ss)
        return a.t.ss<b.t.ss;
    return false;
}

int getTimePoint(const time& a)
{
    return a.hh*3600+a.mm*60+a.ss;
}

char* getTimePeriod(int time)
{
    int hour = time/3600;
    int minute = (time-hour*3600)/60;
    int second = time-hour*3600-minute*60;
    char *s = (char*)malloc(sizeof(char)*10);
    fill(s,s+10,0);
    sprintf(s,"%02d:%02d:%02d",hour,minute,second);
    return s;
}

int main2()
{
    ios::sync_with_stdio(false);
    map<string,int> mp;
    map<string,int>::iterator mpit;
    pair<string,pair<int,int> > valid_record;
    vector<pair<string,pair<int,int> > > valid_list;
    int n,k;
    cin>>n>>k;

    record rs[n];
    time qs[k];
    char t;
    string status;
    for(int i=0;i<n;i++)
    {
        cin>>rs[i].id>>rs[i].t.hh>>t>>rs[i].t.mm>>t>>rs[i].t.ss>>status;
        if(status=="in")
            rs[i].status = 1;
        else
            rs[i].status = 0;
    }
    for(int i=0;i<k;i++)
        cin>>qs[i].hh>>t>>qs[i].mm>>t>>qs[i].ss;

    sort(rs,rs+n,cmpNameTime);
    for(int i=0;i<n;i++)
        cout<<rs[i].id<<" "<<rs[i].t.hh<<":"<<rs[i].t.mm<<":"<<rs[i].t.ss<<rs[i].status<<endl;
    for(int i=0;i<n;i++)
    {
        string id = rs[i].id;
        mpit = mp.find(id); //mp中只存进入记录
        if(mpit!=mp.end() && rs[i].status==0)
        {
            valid_record.first = id;
            valid_record.second.first = mpit->second;
            valid_record.second.second = getTimePoint(rs[i].t);
            valid_list.push_back(valid_record);
            mp.erase(mpit);
        }
        else if(mpit==mp.end() && rs[i].status==1)
        {
            mp[id] = getTimePoint(rs[i].t);
        }
        else
            ;
    }
    for(int i=0;i<k;i++)
    {
        int count = 0;
        int crr = getTimePoint(qs[i]);
        for(int j=0;j<valid_list.size();j++)
        {
            if(valid_list[j].second.first<crr && valid_list[j].second.second>crr)
            {
                count++;
                string s,e;

                cout<<valid_list[j].first<<getTimePeriod(valid_list[j].second.first)<<' '<<getTimePeriod(valid_list[j].second.second)<<endl;
            }
        }
        cout<<count<<endl;
    }
    int time_max;
    string id_max;

    map<string,int> mp2;
    map<string,int>::iterator mpit2;
    for(int i=0;i<valid_list.size();i++)
    {
        int period = valid_list[i].second.second-valid_list[i].second.first;
        mpit2 = mp2.find(valid_list[i].first);
        if(mpit2!=mp2.end())
            mpit2->second += period;
        else
            mp2[valid_list[i].first] = period;
    }

    vector<string> stringv;
    int maxtime=0;
    for(mpit2=mp2.begin();mpit2!=mp2.end();++mpit2)
    {
        if(mpit2->second<maxtime)
            continue;
        else if(mpit2->second>maxtime)
        {
            stringv.clear();
            maxtime = mpit2->second;
        }
        stringv.push_back(mpit2->first); // mpit2->second>=maxtime
    }

    for(int i=0;i<stringv.size();i++)
        cout<<stringv[i]<<' ';
    char* s = getTimePeriod(maxtime);
    string rets = s;
    cout<<rets<<endl;
    free(s);

    return 0;
}

