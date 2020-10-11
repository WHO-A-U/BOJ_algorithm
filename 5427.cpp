#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
char d[1001][1001];
int time[1001][1001];
bool visit[1001][1001];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
queue<pair<int,int>> q;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int c,r;
        memset(visit,false,sizeof(visit));
        cin>>c>>r;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                time[i][j]=0x3f3f3f3f;
            }
        }
        int sr,sc;
        string s;
        for(int i=0;i<r;i++){
            cin>>s;
            for(int j=0;j<c;j++){
                d[i][j]=s[j];
                if(s[j]=='*'){
                    q.push({i,j});
                    time[i][j]=0;
                }
                if(s[j]=='@'){
                    sr = i;
                    sc = j;
                }
            }
        }
        while(!q.empty()){
            int cr = q.front().first;
            int cc = q.front().second;
            int cur = time[cr][cc];
            q.pop();
            for(int i=0;i<4;i++){
                int nr = cr + dx[i];
                int nc = cc+ dy[i];
                if(nr>=0&&nr<r&&nc>=0&&nc<c&&d[nr][nc]!='#'){
                    if(time[nr][nc]>cur+1){
                        time[nr][nc]=cur+1;
                        q.push({nr,nc});
                    }
                }
            }
        }

        queue<pair<pair<int,int>,int>> sanggeun;
        sanggeun.push({{sr,sc},0});
        visit[sr][sc]=true;
        bool flag = false;
        int ans;
        while(!sanggeun.empty()){
            int cr = sanggeun.front().first.first;
            int cc = sanggeun.front().first.second;
            int cur = sanggeun.front().second;
            sanggeun.pop();
            for(int i=0;i<4;i++){
                if(flag)
                    break;
                int nr = cr +dx[i];
                int nc = cc + dy[i];
                if(nr>=0&&nr<r&&nc>=0&&nc<c){
                    if(!visit[nr][nc]&&d[nr][nc]!='#'&&time[nr][nc]>cur+1){
                        visit[nr][nc]=true;
                        sanggeun.push({{nr,nc},cur+1});
                    }
                }else{
                    flag=true;
                    ans=cur+1;
                }
            }
            if(flag)
                break;
        }
        if(flag){
            cout<<ans<<'\n';
        }
        else{
            cout<<"IMPOSSIBLE\n";
        }

    }
}