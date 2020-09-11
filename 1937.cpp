#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int d[501][501];
int dp[501][501];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n;
int go(int r,int c){
    if(dp[r][c]!=-1)
        return dp[r][c];
    dp[r][c]=1;
    int tmp=0;
    for(int i=0;i<4;i++){
        int nr = r+dx[i];
        int nc = c+dy[i];
        if(nr>=0&&nr<n&&nc>=0&&nc<n&&d[r][c]<d[nr][nc]){
            tmp=max(tmp,go(nr,nc));
        }
    }
    return dp[r][c]=tmp+1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans=max(ans,go(i,j));
        }
    }
    cout<<ans;

    
}