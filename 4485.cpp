#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int dist[126][126];
int d[126][126];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> ans;
    int n;
    while(1)
    {
        cin>>n;
        if(n==0)
            break;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                {
                    dist[i][j]=INF;
                    cin>>d[i][j];}
        queue<pair<int,int>>q;
        q.push({1,1});
        dist[1][1]=d[1][1];
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            int cost=d[x][y];
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=1&&nx<=n&&ny>=1&&ny<=n)
                {
                    if(dist[nx][ny]>dist[x][y]+d[nx][ny])
                        {
                            dist[nx][ny]=dist[x][y]+d[nx][ny];
                            q.push({nx,ny});
                        }
                }
            }
        }
        ans.push_back(dist[n][n]);
    }
    for(int i=1;i<=ans.size();i++)
    {
        cout<<"Problem "<<i<<": "<<ans[i-1]<<'\n';
    }
}