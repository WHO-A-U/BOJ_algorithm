#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
int d[1001][1001];
bool v[1001][1001];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,sr,sc;
    string s;
    cin>>n>>m;
    queue<pii> q;

    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='#')
                d[i][j]=-1;
            if(s[j]=='J'){
                sr = i;
                sc = j;
            }
            if(s[j]=='F'){
                d[i][j]=1;
                v[i][j]=true;
                q.push({i,j});
            }
        }
    }
    memset(v,false,sizeof(v));
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        int cur = d[cr][cc];
        q.pop();
        for(int i=0;i<4;i++){
            int nr = cr+dx[i];
            int nc = cc+dy[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m){
                if(!v[nr][nc]&&d[nr][nc]==0){
                    v[nr][nc]=true;
                    d[nr][nc]=cur+1;
                    q.push({nr,nc});
                }
            }
        }
    }

    memset(v,false,sizeof(v));
    q.push({sr,sc});
    d[sr][sc]=1;
    int ans=INF;
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        int cur = d[cr][cc];
        q.pop();
        for(int i=0;i<4;i++){
            int nr = cr+dx[i];
            int nc = cc+dy[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m){
                if(!v[nr][nc]&&(d[nr][nc]==0||d[nr][nc]>cur+1)){
                    v[nr][nc]=true;
                    d[nr][nc]=cur+1;
                    q.push({nr,nc});
                }
            }else{
                ans=min(cur,ans);
            }
        }
    }

    if(ans!=INF){
        cout<<ans;
    }else{
        cout<<"IMPOSSIBLE";
    }
}