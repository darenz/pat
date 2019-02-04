#include <iostream>
#include <vector>
#include <queue>

/*
8 5
1 3 2 3 4
2 1 5
3 1 6
4 1 7
5 1 8
*/

using namespace std;

typedef struct node
{
    vector<struct node*> childs;
    int level;
} node;

int space_count;
void LevelOrder(node* root)
{
    root->level = 1;
    queue<node*> q;
    q.push(root);
    int crr_count = 0;
    int pre_level=1;
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        for(int i=0;i<temp->childs.size();i++)
        {
            temp->childs[i]->level = temp->level + 1;
            q.push(temp->childs[i]);
        }
        if(temp->level!=pre_level)
        {
            pre_level = temp->level;
            cout<<crr_count<<' ';
            crr_count=0;
        }
        if(temp->childs.size()==0)
        {
            crr_count++;
            if(q.size()==0)
            {
                cout<<crr_count;
                break;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    if(n==0)
        return 0;
    space_count = n-k;
    node nds[n+1];
    int isChild[n+1] = {};
    for(int i=0;i<k;i++)
    {
        int index;
        int num;
        cin>>index>>num;
        for(int j=0;j<num;j++)
        {
            int child;
            cin>>child;
            isChild[child] = 1;
            nds[index].childs.push_back(&nds[child]);
        }
    }
    int iroot=1;
    while(iroot<n+1 && isChild[iroot]!=0) iroot++;
    if(iroot>=n+1) return -1;
    node* root = &nds[iroot];

  //  for(int i=1;i<n+1;i++)
        //cout<<nds[i].childs.size()<<endl;
        //cout<<isChild[i];
    LevelOrder(root);
    return 0;
}
