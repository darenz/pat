#include <iostream>
#include <algorithm>
using namespace std;

void InsertionSort(int *a,int n)
{
    a[0] = a[n];
    int b = a[n];
    while(a[n-1]>b)
    {
        a[n] = a[n-1];
        n--;
    }
    a[n] = b;
}

//错误：当只有左孩子时，访问越界
//void DownAdjust(int *a,int i,int n)
//{
//    if(i*2>n) return;
//        int flag = a[2*i]>=a[2*i+1]?1:2;
//        switch (flag)
//        {
//            case 1: 
//                if(a[i]<a[2*i])
//                {
//                    swap(a[i],a[2*i]);
//                    DownAdjust(a,2*i,n);
//                }
//                break;
//            case 2:
//                if(a[i]<a[2*i+1])
//                {
//                    swap(a[i],a[2*i+1]);
//                    DownAdjust(a,2*i+1,n);
//                }
//                break;
//            default:
//                break;
//        }
//}


//void DownAdjust(int *temp,int low,int high){    //大根堆向下调整
//    int i=low,j=i*2;                  //j为i左子女
//    while(j<=high){                   //存在子女(i为非叶结点时）
//        if(j+1<=high&&temp[j+1]>temp[j]) j=j+1; //两子女中选出大者
//        if(temp[j]>temp[i]){
//            swap(temp[j],temp[i]);    //交换父结点与较大的子结点
//            i=j;
//            j=i*2;
//        }
//        else break;                  //子结点均比夫结点小，不用继续调整
//    }
//}
void DownAdjust(int *a,int i,int n)
{
    if(i*2>n)
        return;
    int flag = 1;
    //本题中不能交换左右孩子，按题干给出的定义
    if(i*2+1<=n && a[i*2]<a[i*2+1])
        flag = 2;
    if(flag==1 && a[i]<a[i*2])
    {
        swap(a[i],a[i*2]);
        DownAdjust(a,i*2,n);
    }
    else if(flag==2 && a[i]<a[i*2+1])
    {
        swap(a[i],a[i*2+1]);
        DownAdjust(a,i*2+1,n);
    }
}

//void DownAdjust(int *a,int i,int n)
//{
//    if(i*2>n)
//        return;
//    if(i*2+1<=n && a[i*2]<a[i*2+1])
//        swap(a[i*2],a[i*2+1]);
//    //保持2*i指向孩子中最大值
//    //堆中左右孩子顺序无所谓
//    if(a[i]<a[i*2])
//    {
//        swap(a[i],a[i*2]);
//        DownAdjust(a,i*2,n);
//    }
//}

void CreateHeap(int *a,int n)
{
    for(int i=n/2;i>=1;i--)
        DownAdjust(a,i,n);
    return;
}

void HeapSort(int *a,int n)
{
    CreateHeap(a,n);
    int total = n;
    for(int i=1;i<=n;i++)
    {
        swap(a[1],a[total--]);
        DownAdjust(a,1,total);
    }
}

void UpAdjust(int *a,int i,int n)
{
    if(i<1) return;
    if(a[i]>a[i/2]) 
    {
        swap(a[i],a[i/2]);
        UpAdjust(a,i/2,n);
    }
}

void HeapInsert(int *a,int &n,int x)
{
    a[++n] = x;
    UpAdjust(a,n,n);
}

int DelTop(int *a,int& n)
{
    int top = a[1];
    a[1] = a[n];
    n--;
    DownAdjust(a,1,n);
    return top;
}

bool Compare(int *a,int *b,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i] != b[i])
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    int a[n+1];
    int tmpa[n+1];
    int b[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        tmpa[i] = a[i];
    }
    for(int i=1;i<=n;i++)
        cin>>b[i];
//    for(int i=1;i<=n;i++)
//        InsertionSort(a,i);
//    HeapSort(a,n);
    for(int i=1;i<=n;i++) 
    {
        bool cmpf = 0;
        InsertionSort(a,i);
        cmpf = Compare(a,b,n);
        if(cmpf == 1)
        {
            cout<<"Insertion Sort"<<endl;
            InsertionSort(a,i+1);
            for(int j=1;j<=n;j++)
            {
                if(j!=1) cout<<" ";
                cout<<a[j];
            }
            return 0;
        }
    }
    bool cmpf = 0;
    CreateHeap(tmpa,n);
    int total = n;
    for(int i=1;i<=n;i++)
    {
        cmpf = Compare(tmpa,b,n);
        if(cmpf == 1)
        {
            cout<<"Heap Sort"<<endl;
            swap(tmpa[1] , tmpa[total--]);
            DownAdjust(tmpa,1,total);
            for(int i=1;i<=n;i++)
            {
                if(i!=1) cout<<" ";
                cout<<tmpa[i];
            }
            return 0;
        }
        swap(tmpa[1] , tmpa[total--]);
        DownAdjust(tmpa,1,total);     
    }
}