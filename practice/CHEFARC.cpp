#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <stdio.h>
#include <math.h>
#include <algorithm>
 
using namespace std;
class pointers
{
    public :
    int xdata;
    int ydata;
    pointers *next;
};
pointers *tempp;
pointers *temp;
class Stack
{
    public:
    pointers *head;
    pointers *tail;
    Stack()
    {
       head = NULL; 
       tail = NULL;
    }
    int enqueue(int x,int y);
    void dequeue();
    void print();
    void cur();
    void bsf(int i,int j, int visit[][101],int arr[][101],int dp[][101],int n,int m,int k1);
};
 
int main()
{
  ios_base::sync_with_stdio(false);
    Stack s;
    int t;
    int i,j,n,m,x,y,k1,k2,arr[101][101],dp1[101][101],visit1[101][101];
    int dp2[101][101],visit2[101][101];
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k1>>k2;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>arr[i][j];
                if(arr[i][j] == 1)
                {
                    dp1[i][j] = -2;
                    dp2[i][j] = -2;
                }
                else
                {
                    dp1[i][j] = 0;
                    dp2[i][j] = 0;
                }
 
                visit1[i][j] = 0;
                visit2[i][j] = 0;
            }
        }
        if(m == 1)
        {
            cout<<"0"<<endl;
            continue;
        }
        s.enqueue(0,0);
        visit1[0][0] = 1;
        s.bsf(0,0,visit1,arr,dp1,n,m,k1);
        s.enqueue(0,m-1);
        visit2[0][m-1] = 1;
        s.bsf(0,m-1,visit2,arr,dp2,n,m,k2);
        int max1 = INT_MIN, count = 0;
        int M = INT_MAX;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(visit1[i][j] != 0 && visit2[i][j] != 0)
                {
                    M = min(M,max(dp1[i][j],dp2[i][j]));
                }
            }
        }
        if(visit1[0][m-1] != 0)
        {
          M = min(M,dp1[0][m-1]);
        }
 
 
        if(M == INT_MAX)
        {
          cout<<-1<<endl;
        }
        else
          cout<<M<<endl;
    }
    return 0;
}
   
void Stack::bsf(int i,int j,int visit[][101],int arr[][101],int dp[][101],int n,int m,int k1)
{
    int p,q,r,s,x,y;
    if(head == NULL)
    {
        return;
    }
    cur();
    dequeue();
 
    if(i-k1 < 0)
        p = 0;
    else 
        p = i-k1;
 
    if(i+k1 > n-1)
        q = n-1;
    else 
        q = i+k1;
 
    if(j-k1 < 0)
        r = 0;
    else 
        r = j-k1;
 
    if(j+k1 > m-1)
        s = m-1;
    else 
        s = j+k1;
 
    for(x=p;x<=q;x++)
    {
        for(y=r;y<=s;y++)
        {
            if(arr[x][y] != 1)
            {
                if( (abs(i-x) + abs(j-y)) <= k1)
                {
                    if(visit[x][y] == 0)
                    {
                       cur();
                       enqueue(x,y);
                       visit[x][y] = 1;
                       dp[x][y] = dp[i][j] + 1;
                    }
                }
            }
        }
    }
    if(head == NULL)
    {
        return;
    }
    i = head->xdata;
    j = head->ydata;
    bsf(i,j,visit,arr,dp,n,m,k1);
}
void Stack::cur()
{
    tempp = head;
}
int Stack::enqueue(int x,int y)
{
    if(head == NULL)
    {
        head = new pointers;
        head->xdata = x;
        head->ydata = y;
        head->next = NULL;
        tail = head;
        return 1;
    }
    else
    {
        temp = new pointers;
        temp->xdata = x;
        temp->ydata = y;
        tail->next = temp;
        tail = temp;
        return 1;
    }
}
void Stack::dequeue()
{
    if(tempp == NULL)
    {
        return;
    }
    if(head == tail)
    {
        head = NULL;
        tail = NULL;
        delete tempp;
        return;
    }
    head = head->next;
    delete tempp;
    return;
}