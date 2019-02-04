#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef struct test_info
{
    char reg_num[15];
    int score;
    int location;
    int local_rank;
} test_info;

bool cmp(test_info a,test_info b) //×¢ÒâcmpµÄÐ´·¨
{
    if(a.score!=b.score)
        return a.score>b.score;
    else
        return strcmp(a.reg_num,b.reg_num)<0 ;
}

int main()
{
    int N;
    vector<vector<test_info> > information;
    scanf("%d",&N);
    if(N==0)
        return 0;
    test_info temp;
    int longest=0;
    for(int i=0;i<N;i++)
    {
        int K;
        scanf("%d",&K);
        vector<test_info> v_t;
        information.push_back(v_t);
        for(int j=0;j<K;j++)
        {
            scanf("%s %d",temp.reg_num,&temp.score);
            temp.location = i+1;
            information[i].push_back(temp);
        }
    }

    int pre_score=0;

    int rank = 0;
    for(int i=0;i<N;i++)
    {
        sort(information[i].begin(),information[i].end(),cmp);
        for(int j=0;j<information[i].size();j++)
        {
            if(information[i][j].score!=pre_score)
                rank = j+1;
            information[i][j].local_rank = rank;
            pre_score = information[i][j].score;
        }
    }

    vector<test_info> v_final;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<information[i].size();j++)
            v_final.push_back(information[i][j]);
    }
    sort(v_final.begin(),v_final.end(),cmp);

    rank=0;
    pre_score = 0;
    printf("%ld\n",v_final.size());
    int CR_count = v_final.size() - 1;
    for(int i=0;i<v_final.size();i++)
    {
        if(v_final[i].score!=pre_score)
            rank = i+1;

        printf("%s %d %d %d",
               v_final[i].reg_num,
               rank,
               v_final[i].location,
               v_final[i].local_rank);
        pre_score = v_final[i].score;
        if(CR_count--)
            printf("\n");
    }


    return 0;
}
