#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<cstdlib>
/*
using namespace std;

#define IN "in"
#define OUT "out"

typedef struct record
{
    string id,state;
    int time;
} record;

int getTime(int h,int m,int s)
{
    return h*3600+m*60+s;
}

string itostring(int a)
{
    char c[5]={0};
    c[0] = a/10 + '0';
    c[1] = a%10 + '0';
    string rs = c;
    return rs;
}

string getTime(int time)
{
    int h,m,s;
    h = time/3600;
    m = (time-h*3600)/60;
    s = time-h*3600-m*60;
    return itostring(h)+":"+itostring(m)+":"+itostring(s);
}

bool cmpNameTime2(record a,record b)
{
    if(a.id!=b.id)
        return a.id<b.id;
    return a.time<b.time;
}

bool cmpTime(record a,record b)
{
    return a.time<b.time;
}

int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    record rcd[n];
    record qt[k];
    char c;
    int hh,mm,ss;
    for(int i=0;i<n;i++)
    {
        cin>>rcd[i].id>>hh>>c>>mm>>c>>ss>>rcd[i].state;
        rcd[i].time = getTime(hh,mm,ss);
    }

    for(int i=0;i<k;i++)
    {
        cin>>hh>>c>>mm>>c>>ss;
        qt[i].time = getTime(hh,mm,ss);
    }

    sort(rcd,rcd+n,cmpNameTime2);

    vector<record> valid_list;
    int p1=0,p2=1;
    map<string,int> mp;
    map<string,int>::iterator it;
    int maxTime=0;
    vector<string> maxId;
    while(p2<n)
    {
        if(rcd[p1].id==rcd[p2].id
           && rcd[p1].state==IN
           && rcd[p2].state==OUT)
        {
            valid_list.push_back(rcd[p1]);
            valid_list.push_back(rcd[p2]);

            it = mp.find(rcd[p1].id);
            int tempt = rcd[p2].time - rcd[p1].time;
            if(it==mp.end())
                mp[rcd[p1].id] =  tempt;
            else
                mp[rcd[p1].id] += tempt;
            if(mp[rcd[p1].id]>maxTime)
            {
                maxTime = mp[rcd[p1].id];
                maxId.clear();
                maxId.push_back(rcd[p1].id);
            }
            if(mp[rcd[p1].id]==maxTime && maxId.end()==find(maxId.begin(),maxId.end(),rcd[p1].id))
                maxId.push_back(rcd[p1].id);

            p1 += 2;
            p2 += 2;
        }
        else
        {
            p1++;
            p2++;
        }
    }
    sort(valid_list.begin(),valid_list.end(),cmpTime);


    cout<<"valid :"<<valid_list.size()<<endl;
    for(int i=0;i<valid_list.size();i++)
        cout<<valid_list[i].id<<" "<<getTime(valid_list[i].time)<<valid_list[i].state<<endl;

    cout<<"map:"<<endl;
    for(it=mp.begin();it!=mp.end();it++)
        cout<<it->first<<" "<<it->second<<" ";
    cout<<endl;

    int count_car=0;
    int j=0;
    for(int i=0;i<k;i++)
    {
        int check=qt[i].time;
        while(j<valid_list.size() && valid_list[j].time<=check)
        {
            if(valid_list[j].state==OUT)
                count_car--;
            else
                count_car++;
            j++;
        }
        cout<<count_car<<endl;
    }

    for(int i=0;i<maxId.size();i++)
        cout<<maxId[i]<<' ';
    cout<<getTime(maxTime)<<endl;

}
*/
