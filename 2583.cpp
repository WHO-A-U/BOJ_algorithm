#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> ans;
int d[101][101];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x,y,k;
    cin>>y>>x>>k;
    int x1,y1,x2,y2;
    for(int i=0;i<k;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        for(int j=x1;j<x2;j++)
        {
            for(int k=y1;k<y2;k++)
            {
                d[j][k]=1;
            }
        }
    }
    queue<pair<int,int>>q;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            
            if(d[i][j]==0)
            {
                int cnt=0;
                q.push({i,j});
                while(!q.empty())
                {
                    int cx=q.front().first;
                    int cy=q.front().second;
                    q.pop();
                    if(d[cx][cy]==1)
                        continue;
                    d[cx][cy]=1;
                    cnt++;
                    for(int k=0;k<4;k++)
                    {
                        int nx=cx+dx[k];
                        int ny=cy+dy[k];
                        if(nx>=0&&nx<x&&ny>=0&&ny<y&&(d[nx][ny]==0)){
                            q.push({nx,ny});
                        }
                    }
                }
                ans.push_back(cnt);
            }
           
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }   


}