#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int d[51][51];
char map[51][51];
int dist[51][51];
int r,c,sr,sc,maxtime=0;
int er,ec;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void vision(){
    memset(d,-1,sizeof(d));
    queue<pair<int,int>> q;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(map[i][j]=='*'){
                q.push({i,j});
                d[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        int dist = d[cr][cc];
        q.pop();
        for(int i=0;i<4;i++){
            int nr = cr+dx[i];
            int nc = cc+dy[i];
            if(nr>=0&&nr<r&&nc>=0&&nc<c&&map[nr][nc]!='X'&&map[nr][nc]!='D'){
                if(d[nr][nc]==-1||d[nr][nc]>dist+1){
                    d[nr][nc]=dist+1;
                    q.push({nr,nc});
                }
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            maxtime=max(maxtime,d[i][j]);
        }
    }
    
}
int isPossible(){
    memset(dist,-1,sizeof(dist));
    queue<pair<int,int>>q;
    q.push({sr,sc});
    dist[sr][sc]=0;
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        int cost=dist[cr][cc];
        q.pop();
        for(int i=0;i<4;i++){
            int nr = cr+dx[i];
            int nc = cc+dy[i];
            if(nr>=0&&nr<r&&nc>=0&&nc<c&&map[nr][nc]!='X'){
                if(d[nr][nc]>cost+1||d[nr][nc]==-1){
                    if(dist[nr][nc]==-1||dist[nr][nc]>cost+1){
                        dist[nr][nc]=cost+1;
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
    return dist[er][ec];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>r>>c;
    for(int i=0;i<r;i++){
        string str;
        cin>>str;
        for(int j=0;j<c;j++){
            map[i][j]=str[j];
            {
                if(map[i][j]=='S'){
                    sr=i;
                    sc=j;
                }
                if(map[i][j]=='D'){
                    er=i;
                    ec=j;
                }
            }
        }
    }
    vision();
    int ans=isPossible();
    if(ans==-1){
        cout<<"KAKTUS";
    }
    else{
        cout<<ans;
    }
    
}