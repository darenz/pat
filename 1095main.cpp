#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef struct record
{
    int ih,im,is;
    int oh,om,os;
    int inf,outf;
} record;

int main()
{
    ios::sync_with_stdio(false);
    map<string,record> mp;
    map<string,record>::iterator it,erase_it;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        string id,status;
        int h,m,s;
        char t;
        cin>>id;
        cin>>h>>t>>m>>t>>s;
        cin>>status;
        it = mp.find(id);
        if(it!=mp.end())
        {
            if(status=="in")
            {
                it->second.ih = h;
                it->second.im = m;
                it->second.is = s;
                it->second.inf = 1;
            }
            else
            {
                it->second.oh = h;
                it->second.om = m;
                it->second.os = s;
                it->second.outf = 1;
            }
        }
        else
        {
            record r;
            if(status=="in")
            {
                r.ih = h;
                r.im = m;
                r.is = s;
                r.inf = 1;
                r.outf = 0;
            }
            else
            {
                r.oh = h;
                r.om = m;
                r.os = s;
                r.outf = 1;
                r.inf = 0;
            }
            mp[id] = r;
        }
    }

    string max_id;
    int max_h,max_m,max_s;
    int totals;
    int maxs=0;
    for(it=mp.begin();it!=mp.end();)
    {
        if(it->second.inf==0 || it->second.outf==0)
        {
            erase_it = it;
            it++;
            mp.erase(erase_it);
        }
        else
        {
            totals = (it->second.oh - it->second.ih)*3600 +
                (it->second.om -it->second.im)*60 +
                it->second.is - it->second.os;
            if(totals > maxs)
            {
                max_id = it->first;
                maxs = totals;
                max_h = maxs/3600;
                max_m = (maxs - max_h*3600)/60;
                max_s = maxs - max_h*3600 - max_m*60;
            }
            ++it;
        }
    }

    for(int i=0;i<k;i++)
    {
        int qh,qm,qs;
        char t;
        cin>>qh>>t>>qm>>t>>qs;
        int count=0;
        for(it=mp.begin();it!=mp.end();++it)
        {
            if(it->second.ih<qh && it->second.oh>qh)
                count++;
            else if(it->second.ih==qh && it->second.oh==qh)
            {
                if(it->second.im<qm && it->second.om>qm)
                    count++;
                else if(it->second.im==qm && it->second.om==qm)
                {
                    if(it->second.im<qs && it->second.om>qs)
                        count++;
                }
            }
        }
        cout<<count<<endl;
    }
    cout<<max_id<<' ';
    cout<<setw(2)<<setfill('0')<<max_h;
    cout<<':';
    cout<<setw(2)<<setfill('0')<<max_m;
    cout<<':';
    cout<<setw(2)<<setfill('0')<<max_s;
    return 0;
}
