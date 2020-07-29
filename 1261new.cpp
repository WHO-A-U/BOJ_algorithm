#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
bool d[101][101];
int dist[101][101];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool visit[101][101];
int main()
{
    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)
            dist[i][j]=INF;
    priority_queue<pair<int,int>>q;
    int row,col,a;
    cin>>col>>row;
    for(int i=1;i<=row;i++)
        for(int j=1;j<=col;j++)
            {
                scanf("%1d",&a);
                d[i][j]=(a==1?true:false);
            }
    
    dist[1][1]=0;
    q.push({1,1});
    int ans=0;
    while(!q.empty())
    {
        int cur_row=q.top().first;
        int cur_col=q.top().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int n_r=cur_row+dx[i];
            int n_c=cur_col+dy[i];
            int tmp=(d[n_r][n_c]==true?1:0);
            if(n_r>=1&&n_r<=row&&n_c>=1&&n_c<=col&&dist[n_r][n_c]>dist[cur_row][cur_col]+tmp)
            {
                dist[n_r][n_c]=dist[cur_row][cur_col]+tmp;
                q.push({n_r,n_c});
            }
        }
    
    }
    cout<<dist[row][col];
}