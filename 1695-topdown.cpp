#include <bits/stdc++.h>
using namespace std;
int d[5001];
int dp[5001][5001];
int n;
int go(int l ,int r){
    if(l==r)return 1;
    
    int &ret = dp[l][r];
    if(ret!=-1)
        return ret;

    if(l>r)
        return ret=0;

    if(d[l]==d[r])
        ret = go(l+1,r-1)+2;
    ret = max({ret , go(l+1,r),go(l,r-1)});
    
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp,-1,sizeof(dp));
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    cout<<n-go(0,n-1);
}