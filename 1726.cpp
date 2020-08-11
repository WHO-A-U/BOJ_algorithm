#include<iostream>
#include<queue>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int d[101][101][4];
int wall[101][101];
int n,m;
int x1,y1,d1,x2,y2,d2;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int t[]={1,-1};

// 방향은 동쪽이 1, 서쪽이 2, 남쪽이 3, 북쪽이 4로 주어진다

// 북 0 동 1 남 2 서 3

int trans(int x){
    if(x==1)return 1;
    if(x==2)return 3;
    if(x==3)return 2;
    if(x==4)return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(d,-1,sizeof(d));
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>wall[i][j];
        }
    }
    cin>>x1>>y1>>d1>>x2>>y2>>d2;
    x1--;
    y1--;
    x2--;
    y2--;
    d1=trans(d1);
    d2=trans(d2);
    queue<pair<pair<int,int>,pair<int,int>>> q; // {row, col} , {dir,cnt};
    q.push({{x1,y1},{d1,0}});
    d[x1][y1][d1]=0;
    while(!q.empty()){
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int cdir = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();
        if(cr==x2&&cc==y2&&cdir==d2){
            continue;   
        }
        for(int k=1;k<=3;k++){
            int nr = cr+dx[cdir]*k;
            int nc = cc+dy[cdir]*k;
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&wall[nr][nc]==0){
                if(d[nr][nc][cdir]==-1||d[nr][nc][cdir]>cost+1){
                    d[nr][nc][cdir]=cost+1;
                    q.push({{nr,nc},{cdir,cost+1}});
                }
            }else{
                break;
            }
        }

        for(int i=0;i<2;i++){
            int ndir = (cdir+t[i]+4)%4;
            if(d[cr][cc][ndir]==-1||d[cr][cc][ndir]>cost+1){
                d[cr][cc][ndir]=cost+1;
                q.push({{cr,cc},{ndir,cost+1}});
            }
        }
    }
    cout<<d[x2][y2][d2];
}