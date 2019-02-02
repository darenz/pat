#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

/*
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0

1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -
*/
typedef struct User
{
	int uid;
	int scores[6];
	int total;
	int flags[6];
	int perfect;
	int pass;
} User;

User users[10010];

bool cmp(User a,User b)
{
	if(a.total!=b.total)
		return a.total>b.total;
	if(a.perfect!=b.perfect)
		return a.perfect>b.perfect;
	return a.uid<b.uid;
}

int k;
int getTotal(User& a)
{
	int total=0;
	for(int i=1;i<=k;i++)
	{
		total += a.scores[i];
		if(a.scores[i]!=-1 && a.scores[i]!=0)
			a.pass = 1;
	}
	return total;
}

int getNum()
{
	int sum=0;
	for(int i=0;i<10010;i++)
		sum += (users[i].uid!=0);
	return sum;
}

int main(int argc, char const *argv[])
{
	int N,M;
	scanf("%d %d %d",&N,&k,&M);
	int full_mark[6] = {};
	for(int i=1;i<=k;i++)
		scanf("%d",&full_mark[i]);

	int user_count=0;
	for(int i=0;i<M;i++)
	{
		int uid,pro,score;
		scanf("%d %d %d",&uid,&pro,&score);
		if(users[uid].uid==0)
			users[uid].uid = uid;
		if(score>users[uid].scores[pro])
			users[uid].scores[pro] = score;
		if(score == full_mark[pro])
			users[uid].perfect++;
		users[uid].flags[pro] = 1;
	}

	user_count = getNum(); 
	User newUsers[user_count];
	int j=0;
	for(int i=0;i<user_count;i++)
	{
		while(j<10010 && users[j].uid==0) j++;
		if(j<10010)
		{
			newUsers[i] = users[j++];
			newUsers[i].total = getTotal(newUsers[i]);
		}
		else
			break;
	}
	sort(newUsers,newUsers+user_count,cmp);
	int rank,pre_rank;
	for(int i=0;i<user_count;i++)
	{
		if(i==0)
			pre_rank = rank = 1;
		else if(newUsers[i].total == newUsers[i-1].total)
			rank = pre_rank;
		else
			pre_rank = rank = i+1;
		if(newUsers[i].pass == 0)
			continue;
		printf("%d %05d %d",rank,newUsers[i].uid,newUsers[i].total);
		for(int j=1;j<=k;j++)
		{
			if(newUsers[i].flags[j]!=0)
				printf(" %d",newUsers[i].scores[j] );
			else
				printf(" -");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
