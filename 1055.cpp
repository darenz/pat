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

bool cmpWorthAgeName(Person a,Person b)
{
	if(a.worth!=b.worth)
		return a.worth>b.worth;
	if(a.age!=b.age)
		return a.age<b.age;
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
	
	sort(info,info+N,cmpWorthAgeName);
	for(int i=0;i<k;i++)
	{
		int qn,min,max;
        scanf("%d %d %d",&qn,&min,&max);
		printf("Case #%d:\n",i+1);
		int j=0;
		int count = 0;
		while(j<N && count<qn)
		{
			if(info[j].age>=min && info[j].age<=max)
			{
				if(strcmp(info[j].name,"Nobody")!=0)
				{
					printf("%s %d %ld\n",info[j].name,info[j].age,info[j].worth);
					count++;
				}
			}
			j++;
		}
		if(count==0)
			printf("None\n");
	}
	

/*
	//超时算法

	sort(info,info+N,cmpAge);
	int nout;
	int min,max;
	for(int i=0;i<k;i++)
	{
		printf("Case #%d:\n",i+1 );

		min = q[i].min_age;
        max = q[i].max_age;
        nout = q[i].num;

		int loc_age1,loc_age2;
		loc_age1 = 0;
		while(loc_age1<N) 
		{
			if(info[loc_age1].age<min)
				loc_age1++;
			else
				break;
		}
		loc_age2 = loc_age1;
		while(loc_age2<N)
		{
			if(info[loc_age2].age<=max)
				loc_age2++;
			else
				break;
		}
			
		loc_age2--;
		if(loc_age2-loc_age1<0)
		{
			printf("None\n");
			continue;
		}
		int n1 = loc_age2-loc_age1+1;
		Person temp[n1];
		for(int j=0;j<n1;j++)
			temp[j] = info[loc_age1+j];
		sort(temp,temp+n1,cmpWorthName);
		for(int j=0;j<(n1>nout?nout:n1);j++)
		{
			if(strcmp(temp[j].name,"Nobody")==0)
				j--;
			printf("%s %d %ld\n",temp[j].name,temp[j].age,temp[j].worth);	
		}
    }
*/
	//system("pause");
    return 0;
}

//add another new line
