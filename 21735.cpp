#include <bits/stdc++.h>
using namespace std;
int d[201];
int n,m,ans=0;
void go(int cnt,int idx,int val){
    
    if(idx>=0 && idx<n)
        val+=d[idx];

    if(cnt==0 || idx >= n){
        ans = max(ans , val);
        return ;
    }

    go(cnt-1,idx+1,val);
    go(cnt-1,idx+2,val/2);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;    
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    go(m,-1,1);

    cout<<ans;
}