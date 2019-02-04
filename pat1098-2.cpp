#include <iostream>
#include <algorithm>

using namespace std;
int b[1000];

int B[1000];
bool Insertion_Sort(int a[],int n){
    int Tmp,i;
    bool done = false;
    for(int p=2;p<=n;p++){
        bool flag = true;
        Tmp = a[p];
        for( i = p;i>0&&a[i-1]>Tmp;i--){
            a[i]=a[i-1];
        }
        a[i] = Tmp;
        for(int i = 1;i<=n;i++){
            if(a[i]!=B[i])
                flag = false;
        }
        if(flag){
            done = true;
            continue;
        }
        if(done){
            return true;
        }
 
    }
    return false;
}

void InsertSortOnce(int a[],int i)
{
    if(i==1)
        return;
    a[0] = a[i];
    while(a[i-1]>a[0])
    {
        a[i] = a[i-1];
        i--;
    }
    a[i] = a[0];
}

void DownAdjust(int a[],int i,int n)
{
    int j = 2*i;
    while(j<=n){
        if(j+1<=n && a[j]<a[j+1])
            j = j+1;
        if(a[i]<a[j]) 
            swap(a[i],a[j]);
        else
            break;
        
        i = j;
        j = 2*j;
    }
}

bool Compare(int a[],int b[],int n)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    if(n==0)
        return 0;
    int a1[101];
    int a2[101];
    for(int i=1;i<=n;i++)
    {
        cin>>a1[i];
        a2[i] = a1[i];
    }
    for(int i=1;i<=n;i++)
        cin>>B[i];
    for(int i=1;i<=n;i++)
    {
        int flag = Compare(a1,B,n);
        InsertSortOnce(a1,i);
        if(flag == true)
        {
            cout<<"Insertion Sort"<<endl;
            for(int j=1;j<=n;j++)
            {
                if(j!=1) cout<<' ';
                cout<<a1[j];
            }
            return 0;
        }
    }
    for(int i=n/2;i>=1;i--)
        DownAdjust(a2,i,n);
    for(int i=n;i>1;i--) 
    {
        int flag = Compare(a2,B,n);
        swap(a2[1],a2[i]);
        DownAdjust(a2,1,i-1);
        if(flag == true)
        {
            cout<<"Heap Sort"<<endl;
            for(int j=1;j<=n;j++)
            {
                if(j!=1) cout<<' ';
                cout<<a2[j];
            }
            return 0;
        }
    }
    
}