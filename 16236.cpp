#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n;
int x,r,c,time=0,shark=2;
int sharksize=shark;
int d[21][21];
int v[21][21];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool bfs(){
    queue<pair<int,int>> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            v[i][j]=0x3f3f3f3f;
        }
    }
    q.push({r,c});
    v[r][c]=0;
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nr = cr+dx[i];
            int nc = cc+dy[i];
            if(nr>=1&&nr<=n&&nc>=1&&nc<=n){
                if(d[nr][nc]<=shark&&v[nr][nc]>v[cr][cc]+1)
                {
                    v[nr][nc]=v[cr][cc]+1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int tr = 0x3f3f3f;
    int tc = 0x3f3f3f;
    int td = 0x3f3f3f;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(d[i][j]>0&&d[i][j]!=9&&d[i][j]<shark){
                if(v[i][j]<td){
                    td=v[i][j];
                    tr=i;
                    tc=j;
                }
            }
        }
    }
    if(td==0x3f3f3f)
        return false;
    sharksize--;
    if(sharksize==0)
    {
        shark++;
        sharksize=shark;
    }
    d[r][c]=0;
    r=tr;
    c=tc;
    d[tr][tc]=9;
    time+=td;
    return true;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>d[i][j];
            if(d[i][j]==9){
                r=i;
                c=j;
            }
        }
    }
    while(bfs());
    cout<<time;
}