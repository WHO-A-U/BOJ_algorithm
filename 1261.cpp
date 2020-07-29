#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#define INF 10000
using namespace std;
bool d[101][101];
int cost[101][101];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool visit[101][101];
int main()
{
    priority_queue<pair<int,pair<int,int>>>q;
    int row,col,a;
    cin>>col>>row;
    for(int i=1;i<=row;i++)
        for(int j=1;j<=col;j++)
            {
                scanf("%1d",&a);
                d[i][j]=(a==1?true:false);
            }
    
     for(int i=1;i<=row;i++)
        {   
            for(int j=1;j<=col;j++)
                cout<<d[i][j]<<" ";
            cout<<endl;
        }
    visit[1][1]=true;
    q.push({0,{1,1}});
    int ans=0;
    while(!q.empty())
    {
        int blockcnt=-q.top().first;
        int cur_row=q.top().second.first;
        int cur_col=q.top().second.second;
        q.pop();
        if(cur_row==row && cur_col==col){
            ans=blockcnt;
            break;
        }
        else
        {
            for(int i=0;i<4;i++)
            {
                int n_r=cur_row+dx[i];
                int n_c=cur_col+dy[i];
                if(n_r>=1&&n_r<=row&&n_c>=1&&n_c<=col&&visit[n_r][n_c]==false)
                {
                    q.push({-((d[n_r][n_c]?1:0)+blockcnt),{n_r,n_c}});

                }
            }
        }
    }
    cout<<ans;
}