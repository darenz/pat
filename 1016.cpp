#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define ONLINE 1
#define OFFLINE 0

//bool cmp(Record a,Record b);
//void caculateFee(const Record *p1,const Record *p2,int *time,float *fee_once,int* rate,int ALLDAY);

typedef struct Record
{
    char name[25];
    int month,day,hour,minute;
    int flag;
} Record;

bool cmp(Record a,Record b)
{
    if(strcmp(a.name,b.name)!=0)
        return strcmp(a.name,b.name)<0 ;
    if(a.month!=b.month)
        return a.month<b.month;
    if(a.day!=b.day)
        return a.day<b.day;
    if(a.hour!=b.hour)
        return a.hour<b.hour;
    if(a.minute!=b.minute)
        return a.minute<b.minute;
    else
        printf("erro");
    return 0;
}

void caculateFee(const Record *p1,const Record *p2,int *time,float *fee_once,int* rate,int ALLDAY)
{
    int startd = p1->day;
    int startd_t = startd;

    int starth = p1->hour;
    int starth_t = starth;
    int startm = p1->minute;

    int endd = p2->day;
    int endh = p2->hour;
    int endm = p2->minute;

    float fee=0;
    *time = (endd-startd)*60*24 -starth*60 + endh*60 - startm + endm;
    
    while(startd_t<endd-1)
    {
        fee += ALLDAY;
        startd_t++;
    }
    if(startd_t<endd)
    {
        while(starth_t<24 || starth_t%24!=endh)
        {
            fee += 60*rate[starth_t%24];
            starth_t++ ;
        }
    }
    else
    {
        while(starth_t<endh)
            fee += 60*rate[starth_t++];
    }

    fee = fee - startm*rate[starth] + endm*rate[endh];
    *fee_once = fee/100;

//    if(startd<endd)
//    {
//        if(starth<endh)
//            fee = fee + ALLDAY*(endd-startd);
//        else
//            fee = fee + ALLDAY*(endd-startd-1);
//    }
//
//    while(starth_t!=endh)
//    {
//        fee = fee + 60*rate[starth_t];
//        starth_t = (starth_t+1)%24;
//    }
//        
//    fee = fee - startm*rate[starth] + endm*rate[endh];
//    *fee_once = fee/100;
}

int main()
{
    int N;
    int rate[24];
    int ALLDAY=0;

    for(int i=0;i<24;i++)
    {
        scanf("%d",&(rate[i]));
        ALLDAY += rate[i]*60;        
    }
    scanf("%d",&N);
    if(N==0)
        return 0;
    Record records[N];
    char act[10];
    for(int i=0;i<N;i++)
    {
        scanf("%s %d:%d:%d:%d %s",records[i].name,&records[i].month,&records[i].day,&records[i].hour,&records[i].minute,act);

        if(strcmp(act,"on-line")==0) 
            records[i].flag = ONLINE;
        else
            records[i].flag = OFFLINE;
    }
    

    //printf("\n%d\n",ALLDAY);
    sort(records,records+N,cmp);
    Record *p1 = records;
    Record *p2 = p1+1;
    
    float fee = 0;
    char crr_name[25];
    strcpy(crr_name,p1->name);
            
    int time ;
    float fee_once ;

    while(p2<records+N) //能不能访问
    {
        if(strcmp(crr_name,p1->name)==0 && strcmp(crr_name,p2->name) == 0)//是不是同一个人
        {//是
            if(p1->flag == ONLINE && p2->flag == OFFLINE)//是不是一对
            {//yes
                //边计算边输出
                //每次的输出量重置
                fee_once = 0;
                time = 0;
                caculateFee(p1,p2,&time,&fee_once,rate,ALLDAY);
                if(fee==0) //第一次输出
                    printf("%s %02d\n",p1->name,p1->month);
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%02.2f\n",p1->day,p1->hour,p1->minute,p2->day,p2->hour,p2->minute,time,fee_once);
                fee += fee_once;
                p1 += 2;
                p2 += 2;
            }
            else
            {//no
                p1++;
                p2++;
            }
        }
        else
        {//不是
            //输出前一个人总的
            if(fee!=0) // 是不是需要输出
                printf("Total amount: $%.2f\n",fee);
        
            //改下一个人
            strcpy(crr_name,p2->name);
            fee = 0;
            //顺序不能反
            if(strcmp(p1->name,p2->name)!=0)//是不是都换过来了
            {//no
                p1++;
                p2++;
            }
        }
    }
    if(fee!=0) //到头了,不能继续访问
        printf("Total amount: $%.2f\n",fee);

//printf(“格式控制字符串”，输出表列)
//格式控制字符串 为 %- 0 m.n l/h 格式字符，% 为格式说明的引导符号，- 为指定左对起输出，0 为 指定空位填0，m.n 指定输出域宽及精度，l/h 输出长度的修正，格式字符为指定输出的数据类型。

//    for(int i=0;i<N;i++)
//        printf("%s %d:%d:%d:%d %d\n",records[i].name,records[i].month,records[i].day,records[i].hour,records[i].minute,records[i].flag);
    return 0;
}




