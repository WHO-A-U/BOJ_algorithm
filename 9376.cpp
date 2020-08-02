#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int d[102][102];
int dist[102][102][3];
int entire[102][102];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int r,c;
int bfs(int row,int col,int mode){
    for(int i=0;i<=r+1;i++){
        for(int j=0;j<=c+1;j++){
            dist[i][j][mode]=0x3f3f;
        }
    }
    queue<pair<int,int>> q;
    q.push({row,col});
    dist[row][col][mode]=0;
    while(!q.empty()){

        int cr=q.front().first;
        int cc=q.front().second;
        int cd=dist[cr][cc][mode];
        q.pop();
        for(int i=0;i<4;i++){
            int nr=cr+dx[i];
            int nc=cc+dy[i];
            if(nr>=0&&nr<=r+1&&nc>=0&&nc<=c+1&&d[nr][nc]!=-1){
                if(d[nr][nc]==1){
                    if(dist[nr][nc][mode]>cd+1){
                        dist[nr][nc][mode]=cd+1;
                        q.push({nr,nc});
                    }
                }
                else{
                    if(dist[nr][nc][mode]>cd){
                        dist[nr][nc][mode]=cd;
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        vector<pair<int,int>> prison;
        cin>>r>>c;
        prison.push_back({0,0});
        for(int i=0;i<=r+1;i++){
            for(int j=0;j<=c+1;j++){
                char s;
                if(i==0||i==r+1||j==0||j==c+1){
                    d[i][j]=0;
                }
                else{
                    cin>>s;
                    if(s=='*')d[i][j]=-1;
                    if(s=='#')d[i][j]=1;
                    if(s=='.')d[i][j]=0;
                    if(s=='$'){
                        d[i][j]=3;
                        prison.push_back({i,j});
                    }
                }
            }
        }

           
        for(int i=0;i<=r+1;i++)
            for(int j=0;j<=c+1;j++)
                entire[i][j]=0;
        for(int i=0;i<3;i++)
            bfs(prison[i].first,prison[i].second,i);
        for(int i=0;i<=r+1;i++){
            for(int j=0;j<=c+1;j++){
                for(int k=0;k<3;k++){
                    entire[i][j]+=dist[i][j][k];
                }
                if(d[i][j]==1)
                    entire[i][j]-=2;
            }
        }
        int ridx,cidx;
        int minval=0x3f3f3f3f;
        for(int i=0;i<=r+1;i++){
            for(int j=0;j<=c+1;j++){
                if(entire[i][j]<minval){
                    minval=entire[i][j];
                }
            }
        }
       cout<<minval<<'\n';
    }
}