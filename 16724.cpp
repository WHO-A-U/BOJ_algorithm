#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;
char d[1001][1001];
int dx[]={-1,1,0,0};// UDLR
int dy[]={0,0,-1,1};
pii getdir(int n , int m,char c){
    int i;
    if(c=='U')i=0;
    if(c=='D')i=1;
    if(c=='L')i=2;
    if(c=='R')i=3;
    return {n+dx[i],m+dy[i]};
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h,w;
    cin>>h>>w;
    string s;
    for(int i=0;i<h;i++){
        cin>>s;
        for(int j=0;j<w;j++){
            d[i][j]=s[j];
        }
    }


    vvb visit(h,vb(w));
    queue<pii> q;
    int ans=0;
    int color=1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(!visit[i][j]){
                visit[i][j]=true;
                q.push({i,j});
                ans++;
                while(!q.empty()){
                    int cr = q.front().first;
                    int cc = q.front().second;
                    q.pop();

                    pii ret= getdir(cr,cc,d[cr][cc]);

                    int nr = ret.first;
                    int nc = ret.second;
                    if(!visit[nr][nc]){
                        visit[nr][nc]=true;
                        q.push({nr,nc});
                    }
                
                    for(int k=0;k<4;k++){
                        int nr = cr+dx[k];
                        int nc = cc+dy[k];

                        if(nr>=0&&nr<h&&nc>=0&&nc<w){
                            pii asump = getdir(nr,nc,d[nr][nc]);
                            int sr = asump.first;
                            int sc = asump.second;
                            if(sr==cr&&sc==cc){
                                if(!visit[nr][nc]){
                                    visit[nr][nc]=true;
                                    q.push({nr,nc});
                                }
                            }
                        }
                    }

                }
                color++;
            }
        }
    }
    cout<<ans;
}