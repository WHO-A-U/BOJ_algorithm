#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int d[1001][1001];
int dp[1001][1001][3];
int n,m;
bool isPossible(int a,int b){
    if(a>=0&&a<n&&b>=0&&b<m)return true;
    return false;
}
int go(int r , int c , int dir){
    if(r==0&&c==0)
        return d[r][c];

    int &ret = dp[r][c][dir];

    if(ret!=-1)
        return ret;
    ret =-INF;
    if(isPossible(r-1,c))
        ret = max({ret,go(r-1,c,0),go(r-1,c,1),go(r-1,c,2)});
    if(isPossible(r,c-1)&&dir==1)
        ret = max(ret , go(r,c-1,dir));
    if(isPossible(r,c+1)&&dir==2)
        ret = max(ret , go(r,c+1,dir));

    return ret+=d[r][c];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp,-1,sizeof(dp));
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>d[i][j];
        }
    }
    cout<<max(go(n-1,m-1,0),go(n-1,m-1,1));
}