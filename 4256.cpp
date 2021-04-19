#include <bits/stdc++.h>
using namespace std;
int d[1001][2];
int node[1001][2];
int n,t;
int go(int l1,int r1 , int l2,int r2){
    int cur = d[l1][0];
   
    if(l1>r1 || l2>r2)
        return 0;
    if(l1==r1)
        return cur;
    
    int idx=-1;
    for(int i=l2;i<=r2;i++){
        if(cur==d[i][1]){
            idx=i;
            break;
        }
    }
    int lc = idx-l2;
    node[cur][0] = go(l1+1,l1+lc,l2,idx-1);
    node[cur][1] = go(l1+lc+1,r1,idx+1,r2);

    return cur;
}
void postOrder(int cur){
    if(node[cur][0]!=0)postOrder(node[cur][0]);
    if(node[cur][1]!=0)postOrder(node[cur][1]);
    cout<<cur<<" ";
}
void solve(){
    cin>>n;
    memset(d,0,sizeof(d));
    memset(node,0,sizeof(node));
    for(int i=0;i<n;i++)
        cin>>d[i][0];
    for(int i=0;i<n;i++)
        cin>>d[i][1];

    postOrder(go(0,n-1,0,n-1));
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        solve();
    }
}