#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int d[101][101];
int visit[101][101];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int row,col,tlimit;
    int x,y;
    cin>>row>>col>>tlimit;
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            cin>>d[i][j];
            visit[i][j]=987654321;
            if(d[i][j]==2){
                x=i,y=j;
            }
        }
    }
    queue<pair<int,int>> q;
    visit[1][1]=0;
    q.push({1,1});
    while(!q.empty()){
        int crow=q.front().first;
        int ccol=q.front().second;
        int ctime=visit[crow][ccol];
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nrow=crow+dx[i];
            int ncol=ccol+dy[i];
           if(nrow>=1 &&nrow<=row && ncol>=1 && ncol<=col&&d[nrow][ncol]!=1){
                if( visit[nrow][ncol]>visit[crow][ccol]+1){
                    visit[nrow][ncol]=visit[crow][ccol]+1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int ans=min(visit[row][col],visit[x][y]+(row-x)+(col-y));
    if(ans<=tlimit){
        cout<<ans;
    }
    else{
        cout<<"Fail";
    }
}