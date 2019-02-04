#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct User
{
    User()
    {
        for(int i=0;i<6;i++)
            scores[i] = -2;
        pass = 0;
        perfect = 0;
        id = 0;
        total = 0;
    }
    int scores[6];
    int perfect;
    int pass;
    int total;
    int id;
} User;

bool cmp(User& a,User& b)
{
    if(a.total!=b.total)
        return a.total>b.total;
    if(a.perfect!=b.perfect)
        return a.perfect>b.perfect;
    return a.id<b.id;
}

int main(int argc, char const *argv[])
{
    int N,k,M;
    scanf("%d %d %d",&N,&k,&M);
    int full_score[k+1];
    for(int i=1;i<=k;i++)
        scanf("%d",&full_score[i]);
    User users[N+1];
    
    int uid,pid,st;
    for(int i=0;i<M;i++)
    {
        scanf("%d %d %d",&uid,&pid,&st);
        if(users[uid].id == 0)
            users[uid].id = uid;
        if(users[uid].scores[pid]==-2 && (st==0 || st==-1))
            users[uid].scores[pid] = 0;
        else if(st>users[uid].scores[pid])
        {
            if(users[uid].scores[pid]>0)
                users[uid].total -= users[uid].scores[pid];
            users[uid].scores[pid] = st;
            users[uid].total += st;
            if(st == full_score[pid])
                users[uid].perfect++;
        }
        
        if(st>=0)
            users[uid].pass = 1;
    }
    sort(users+1,users+1+N,cmp);
    int rank;
    int pre_rank;
    for(int i=1;i<=N;i++)
    {
        if(i==1)
            rank = 1;
        else if(users[i].total != users[i-1].total)
            rank = i;
        else ;
        if(users[i].pass == 1)
        {
            
            printf("%d %05d %d",rank,users[i].id,users[i].total);
            for(int j=1;j<=k;j++)
            {
                if(users[i].scores[j]>=0)
                    printf(" %d",users[i].scores[j]);
                else
                    printf(" -");
            }
            printf("\n");
        }
    }
    system("pause");
    return 0;
}
