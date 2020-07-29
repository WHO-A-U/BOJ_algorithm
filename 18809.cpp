#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int d[51][51];
int temp[51][51];
int times[51][51];
int n,m,g,r,ans=0;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
vector<pair<int,int>> Yground;
vector<pair<int,int>> greenspot; ///3
vector<pair<int,int>> redspot;  ///4
void evaluate(){
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(temp[i][j]==7){
                cnt++;
            }
        }
    }
    ans=max(ans,cnt);
}
void bfs(){
    queue<pair<int,int>>q[2];
        int time=0;
    for(int i=0;i<greenspot.size();i++){
        temp[greenspot[i].first][greenspot[i].second]=3;
        times[greenspot[i].first][greenspot[i].second]=-1;
        q[0].push({greenspot[i].first,greenspot[i].second});
    }
    for(int i=0;i<redspot.size();i++){
        temp[redspot[i].first][redspot[i].second]=4;
        times[redspot[i].first][redspot[i].second]=-1;
        q[0].push({redspot[i].first,redspot[i].second});
    }

    while(!q[0].empty()||!q[1].empty()){
        if(q[time].empty()){
            time=(time+1)%2;
        }
        int r=q[time].front().first;
        int c=q[time].front().second;
        int value=temp[r][c];
        q[time].pop();
        if(value==7)
            continue;
        for(int i=0;i<4;i++)
        {
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(nr>=1&&nr<=n&&nc>=1&&nc<=m&&temp[nr][nc]!=0&&temp[nr][nc]!=value){

               
                if(temp[nr][nc]==1||temp[nr][nc]==2){
                    
                    temp[nr][nc]=value;
                    times[nr][nc]=(time+1)%2;
                    q[(time+1)%2].push({nr,nc});

                }else{
                   if(temp[nr][nc]+value==7&&(times[nr][nc]!=times[r][c]))
                        temp[nr][nc]=7;
                }
            }
        }
    }
    evaluate();
}
void makeTable(){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            temp[i][j]=d[i][j];
            times[i][j]=-1;
        }
    }
    bfs();
}
void grid(int index){
    if(index==Yground.size()&&(g>0||r>0))
         return ;
    if(g==0&r==0){
        makeTable();
        return ;
    }

    if(g>0){
        g--;
        greenspot.push_back({Yground[index].first,Yground[index].second});
        grid(index+1);
        greenspot.pop_back();
        g++;
    }
    if(r>0){
        r--;
        redspot.push_back({Yground[index].first,Yground[index].second});
        grid(index+1);
        redspot.pop_back();
        r++;
    }
    grid(index+1);
}
int main()
{
    cin>>n>>m>>g>>r;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>d[i][j];
            if(d[i][j]==2){
                Yground.push_back({i,j});
            }
        }
    }
    grid(0);
    cout<<ans;
}