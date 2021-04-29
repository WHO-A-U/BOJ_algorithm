#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vs = vector<string>;
using vd = vector<double>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vvpii = vector<vpii>;
using vvpll = vector<vpll>;
using vvs = vector<vs>;

vpii edge[101][101];
bool light[101][101];
bool v[101][101];
bool isPossible[101][101];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;
bool isValid(int r , int c){
    return r>=1&&r<=n&&c>=1&&c<=n;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    int r1,c1,r2,c2;
    memset(v,false,sizeof(v));
    for(int i=0;i<m;i++){
        cin>>r1>>c1>>r2>>c2;
        edge[r1][c1].push_back({r2,c2});

    }
    light[1][1]=true;
    queue<pii> q;
    memset(v,false,sizeof(v));
    q.push({1,1});
    v[1][1]=true;    
    while(!q.empty()){
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();
            for(auto p : edge[cr][cc]){
                int lr = p.first;
                int lc = p.second;
                if(!light[lr][lc]){
                    light[lr][lc]=true;
                    if(!v[lr][lc]&&isPossible[lr][lc]){
                        v[lr][lc]=true;
                        q.push({lr,lc});
                    }
                }
            }
            for(int i=0;i<4;i++){
                int nr = cr+dx[i];
                int nc = cc+dy[i];
                if(isValid(nr,nc)){
                    if(light[nr][nc]&&!v[nr][nc]){
                        v[nr][nc]=true;
                        q.push({nr,nc});
                    }else if(!light[nr][nc]){
                        isPossible[nr][nc]=true;
                    }
                }
            }
            
    }
    
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(light[i][j]){
                ans++;
            }
        }
    }
    cout<<ans;
    
}