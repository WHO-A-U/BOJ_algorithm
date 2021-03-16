#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
int d[5001];
int dp[5001][5001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>d[i];
        dp[i][i]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j+i<n;j++){
            if(d[j]==d[j+i])
                dp[j][j+i] = dp[j+1][j+i-1]+2;
            dp[j][j+i] = max({dp[j][j+i],dp[j+1][j+i],dp[j][j+i-1]});
        }
    }
    cout<<n-dp[0][n-1];
}