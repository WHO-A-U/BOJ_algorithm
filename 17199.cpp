#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
int d[101];
vi e[101];
int n,a,b,ans=-1;;
void go(int i){
    d[i]++;
    for(int x : e[i])
        go(x);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        e[a].push_back(b);
    }
    
    for(int i=1;i<=n;i++){
        if(!e[i].empty()){
            d[i]--;
            go(i);
        }
    }
    
    for(int i=1;i<=n;i++)
        if(d[i]==n-1)
            ans=i;
        
    cout<<ans;
    return 0;
}