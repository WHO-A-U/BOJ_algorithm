#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define INF 0x3f3f3f3f
using namespace std;
int d[21][21];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
vector<pair<int,int>> pstart,pend;
int n,m,f,usedFuel;
bool visit[401];
int sr,sc;
int go(int idx){
    int tmp[21][21];
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tmp[i][j]=d[i][j];
            if(tmp[i][j]!=-1)
                tmp[i][j]=INF;
            
        }
    }
    int r = pstart[idx].first;
    int c = pstart[idx].second;
    tmp[r][c]=0;
    bool v[21][21];
    memset(v,false,sizeof(v));
    v[r][c]=true;
     queue<pair<int,int>> q;
     q.push({r,c});
     while(!q.empty()){
         int cr = q.front().first;
         int cc = q.front().second;
         int cost = tmp[cr][cc];
         q.pop();
         for(int i=0;i<4;i++){
             int nr = cr +dx[i];
             int nc = cc+dy[i];
             if(nr>=0&&nr<n&&nc>=0&&nc<n&&(!v[nr][nc]||tmp[nr][nc]>cost+1)&&tmp[nr][nc]!=-1){
                q.push({nr,nc});
                tmp[nr][nc]=cost+1;
                v[nr][nc]=true;
            }
         }
     }
    return tmp[pend[idx].first][pend[idx].second]-tmp[r][c];
}
bool possible(){
    int tmp[21][21];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tmp[i][j]=d[i][j];
            if(tmp[i][j]!=-1)
                tmp[i][j]=INF;
        }
    }
    bool v[21][21];
    memset(v,false,sizeof(v));
    tmp[sr][sc]=0;
    v[sr][sc]=true;
    queue<pair<int,int>> q;
    q.push({sr,sc});
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        int cost = tmp[cr][cc];
        q.pop();
        for(int i=0;i<4;i++){
            int nr = cr +dx[i];
            int nc = cc+ dy[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<n&&(!v[nr][nc]||tmp[nr][nc]>cost+1)&&tmp[nr][nc]!=-1){
                q.push({nr,nc});
                tmp[nr][nc]=cost+1;
                v[nr][nc]=true;
            }
        }
    }
    int ans = 0x3f3f3f3f;
    int idx=-1;
    int nr =0x3f3f3f3f;
    int nc=0x3f3f3f3f;
    for(int i=0;i<m;i++){
        if(!visit[i]){
            if(ans>tmp[pstart[i].first][pstart[i].second]){
                nr = pstart[i].first;
                    nc = pstart[i].second;
                    ans = tmp[pstart[i].first][pstart[i].second];
                    idx=i;
            }
            else if(ans==tmp[pstart[i].first][pstart[i].second]){
                if((nr>pstart[i].first)||(nr==pstart[i].first && nc >pstart[i].second)){
                    nr = pstart[i].first;
                    nc = pstart[i].second;
                    ans = tmp[pstart[i].first][pstart[i].second];
                    idx=i;
                }
            }
        }
    }
    if(idx==-1)
        return false;
    visit[idx]=true;
    f-=ans;
    if(f<0)
        return false;
    int restFuel=f;
    int need = go(idx);
    if( need<0)
        return false;
    f-=need;
    if(f<0)
        return false;
    usedFuel=restFuel-f;
    sr = pend[idx].first;
    sc = pend[idx].second;
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>f;
    memset(visit,false,sizeof(visit));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];
            if(d[i][j]==1)
                d[i][j]=-1;
        }
    }
    cin>>sr>>sc;
    sr--;
    sc--;
    for(int i=0;i<m;i++){
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        r1--;
        c1--;
        r2--;
        c2--;
        pstart.push_back({r1,c1});
        pend.push_back({r2,c2});
    }
    for(int i=0;i<m;i++){
        if(!possible()){
            cout<<"-1";
            return 0;
        }
        f+=(usedFuel*2);
    }
    cout<<f;
}