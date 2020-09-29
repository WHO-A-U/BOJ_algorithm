#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
int dp[501][501];
pair<int,int> v[501];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,a,b;
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        v[i]={a,b};
    }
    dp[1][k]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            for(int z=j;z<=k;z++){
                if(i-(z-j+1)>=1&&dp[i-(z-j+1)][z]>=0){
                    int t = dp[i-(z-j+1)][z];
                    int dist = abs(v[i-(z-j+1)].first-v[i].first)+abs(v[i-(z-j+1)].second-v[i].second);
                    if(dp[i][j]==-1||dp[i][j]>t+dist){
                        dp[i][j]=t+dist;
                    }
                }
            }
        }
    }
    int ans=dp[n][0];
    for(int i=1;i<=k;i++){
        if(dp[n][i]>=0)ans=min(ans,dp[n][i]);
    }
    cout<<ans;
}