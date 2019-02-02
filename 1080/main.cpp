#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct student
{
    int id;
    int GE,GI;
    float gfinal;
    int rank;
    int choices[10];
} student;

class school
{
public:
    school()
    {
        all = 0;
        crr_n = 0;
    }
    int acceptStu(student& a);
    void setAll(int n);
    void output();

private:
    int all;
    int crr_n;
    vector<int> accept;
    int last_rank;

} ;

int school::acceptStu(student& a)
    {//要考虑重复填相同的志愿 --不用
        if(crr_n<all)
        {
            accept.push_back(a.id);
            crr_n++;
            if(crr_n==all)
                last_rank = a.rank;
        }
        else if(a.rank == last_rank)
        {
            accept.push_back(a.id);
            crr_n++;
        }
        else
            return 0;
        return 1;
    }

void school::setAll(int n)
    {
        all = n;
    }



    void school::output()
    {
        if(accept.size()!=0)
        {
            sort(accept.data(),accept.data()+crr_n);
            int space_count = crr_n-1;
            for(int i=0;i<crr_n;i++)
            {
                printf("%d",accept[i]);
                if(space_count-->0)
                    printf(" ");
            }
        }
        else
            return ;
    }

/* //超时排序
bool cmpStu(student a,student b)
{
    if(a.gfinal!=b.gfinal)
        return a.gfinal>b.gfinal;
    if(a.GE!=b.GE)
        return a.GE>b.GE;
    else
        return true;
}
*/

int cmpStu(const void* a1,const void* b1)
{
    student* a = (student*)a1;
    student* b = (student*)b1;
    if(a->gfinal!=b->gfinal)
    {
        if(a->gfinal>b->gfinal)
            return -1;
        else
            return 1;
    }
    if(a->GE!=b->GE)
    {
        if(a->GE>b->GE)
            return -1;
        else
            return 1;
    }
    return 0;
}

int main()
{
    int n_student,n_school,n_choice;
    scanf("%d %d %d",&n_student,&n_school,&n_choice);
    if(n_student == 0 || n_school==0 || n_choice==0)
        return 0;
    student stus[n_student];
    school schs[n_school];

    for(int i=0;i<n_school;i++)
    {
        int n;
        scanf("%d",&n);
        schs[i].setAll(n);
    }

    for(int i=0;i<n_student;i++)
    {
        scanf("%d %d",&stus[i].GE,&stus[i].GI);
        for(int j=0;j<n_choice;j++)
            scanf("%d",&stus[i].choices[j]);
        //必须先转换再计算，否则计算结果是int的精度
        stus[i].gfinal = ((float)stus[i].GE+(float)stus[i].GI)/2;
        stus[i].id = i;
    }
    qsort(stus,n_student,sizeof(student),cmpStu);
    //sort(stus,stus+n_student,cmpStu);
    for(int i=0;i<n_student;i++)
    {
        if(i==0)
            stus[i].rank = 1;
        else if(stus[i].gfinal == stus[i-1].gfinal)
        {
            if(stus[i].GE == stus[i-1].GE)
                stus[i].rank = stus[i-1].rank;
            else
                stus[i].rank = i+1;
        }
        else
            stus[i].rank = i+1;

        int flag = 0;
        for(int j=0;j<n_choice;j++)
        {
            flag = schs[(stus[i].choices[j])].acceptStu(stus[i]);
            if(flag==1)
                break;
        }
    }

    int enter_count = n_school-1;
    for(int i=0;i<n_school;i++)
    {
        schs[i].output();
        printf("\n");
    }
    return 0;
}
