#include <iostream>
#include <cstdio>

using namespace std;

#define UPTIME 6
#define DOWNTIME 4
#define STOPTIME 5
int total_time;

void UpTo(int crr,int aim)
{
    total_time += (aim-crr)*UPTIME;
}

void DownTo(int crr,int aim)
{
    total_time += (crr-aim)*DOWNTIME;
}

int main()
{
    int n;
    cin>>n;
    int crr = 0;
    int aim;
    for(int i=0;i<n;i++)
    {
        cin>>aim;
        if(aim>crr)
            UpTo(crr,aim);
        else 
            DownTo(crr,aim);
        crr = aim;
        total_time += STOPTIME;
    }
    cout<<total_time;
    return 0;
}

