#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int d[9][9];
int temp[9][9];
vector<pair<int,int>> pos; //0's position   height , width
vector<pair<int,int>>virus;
int n,m; //height width
int ans=0;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void bfs(void);
void grade(void);
void makeTable(int a,int b,int c){

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            temp[i][j]=d[i][j];
        }
    }
    int walls[]={a,b,c};
    for(int i=0;i<3;i++)
    {
        int wall=walls[i];
        temp[pos[wall].first][pos[wall].second]=1;
    }
    bfs();
}
void bfs(){
    queue<pair<int,int>> q;
    for(int i=0;i<virus.size();i++)
    {
        q.push({virus[i].first,virus[i].second});
    }
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(nr>=1&&nr<=n&&nc>=1&&nc<=m){
                if(temp[nr][nc]==0){
                    temp[nr][nc]=2;
                    q.push({nr,nc});
                }
            }
        }
    }
    grade();
}
void grade(){
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(temp[i][j]==0){
                cnt++;
            }
        }
    }
    ans=max(ans,cnt);
}

int main()
{

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>d[i][j];
            if(d[i][j]==0){
                pos.push_back({i,j});
            }
            if(d[i][j]==2){
                virus.push_back({i,j});
            }

            
        }
    }
    int poss = pos.size();
    for(int i=0;i<poss-2;i++)
    {
        for(int j=i+1;j<poss-1;j++){

            for(int k=j+1;k<poss;k++)
            {
                makeTable(i,j,k);
            }
        }
    }
    cout<<ans;
}