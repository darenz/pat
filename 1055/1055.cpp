#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct Person
{
	char name[10];
	int age;
	long worth;
} Person;

typedef struct query
{
    int min_age;
    int max_age;
    int num;
} query;

bool cmpAge(Person a,Person b)
{
	if(a.age!=b.age)
		return a.age<b.age;
}

bool cmpWorthName(Person a,Person b)
{
	if(a.worth!=b.worth)
		return a.worth>b.worth;
	int r = strcmp(a.name,b.name);
	return r<0;
}

int main(int argc, char const *argv[])
{
	int k;
	long N;
	rewind(stdin);
	scanf("%ld %d",&N,&k);
	Person info[N];
	for(int i=0;i<N;i++)
	{
		scanf("%s %d %ld",info[i].name,&info[i].age,&info[i].worth);
	}
	query q[k];
	for(int i=0;i<k;i++)
        scanf("%d %d %d",&q[i].num,&q[i].min_age,&q[i].max_age);
	sort(info,info+N,cmpAge);

	int nout;
	int min,max;
	for(int i=0;i<k;i++)
	{
		printf("Case #%d:\n",i+1 );

		min = q[i].min_age;
        max = q[i].max_age;
        nout = q[i].num;

		Person temp[nout];
		int loc_age1,loc_age2;
		loc_age1 = 0;
		while(info[loc_age1++].age<min && loc_age1<N);
		loc_age2 = loc_age1;
		while(info[loc_age2++].age<max && loc_age2<N);
		if(loc_age1==N)
		{
			printf("None\n");
			continue;
		}
		for(int j=0;j<nout && j+loc_age1<=loc_age2;j++)
		{
			temp[j] = info[loc_age1+j];
		}
		sort(temp,temp+nout,cmpWorthName);
		for(int j=0;j<nout;j++)
		{
			printf("%s %d %ld\n",temp[j].name,temp[j].age,temp[j].worth);
        }
    }
    return 0;
}
