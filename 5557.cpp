#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int d[101];
ll dp[101][21];
int n,x;
int dx[]={1,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp,0,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    ll ans=0;
    dp[0][d[0]]=1;
    for(int i=0;i<n-2;i++){
        for(int j=0;j<=20;j++){
            if(dp[i][j]>0){
                for(int k=0;k<2;k++){
                    int next = j+dx[k]*d[i+1];
                    if(next>=0&&next<=20){
                        dp[i+1][next]+=dp[i][j];
                    }
                }
            }
        }
    }

    cout<<dp[n-2][d[n-1]];

    
}