#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int d[201];
int dp[201];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    dp[0]=1;
    for(int i=1;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(dp[j]+1>dp[i]&&d[i]>d[j])
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<n-ans;

}