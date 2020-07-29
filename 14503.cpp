#include<iostream>
#include<vector>
using namespace std;
int d[51][51];
bool visit[51][51];
int n,m,dir,ans=0;
int cr,cc;
//dir 0 북 /1 동 /2 남/ 3 서
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool go(){
    // cout<<"row :"<<cr<<"/ col : "<<cc<<" /dir :"<<dir<<'\n';
    if(visit[cr][cc]==false)
    {
        visit[cr][cc]=true;
        ans++;
    }
    int tmpdir=dir;
    for(int i=0;i<4;i++){
        dir = (dir-1+4)%4;
        int nr = cr+dx[dir];
        int nc = cc+dy[dir];
        if(nr>=0&&nr<n&&nc>=0&&nc<m){
            if(d[nr][nc]==0&&visit[nr][nc]==false){
                cr=nr;
                cc=nc;
                return true;
            }
        }
    }
    dir=tmpdir;
    int br = cr-dx[dir];
    int bc = cc-dy[dir];
    if(d[br][bc]==0){
        cr=br;
        cc=bc;
        return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    cin>>cr>>cc>>dir;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>d[i][j];
        }
    }
    while(go());
    cout<<ans;
}