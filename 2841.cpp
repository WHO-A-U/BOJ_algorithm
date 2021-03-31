#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
vi d[7];
int main(){

   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
    int n,p,a,b,ans=0;
    cin>>n>>p;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        int idx = upper_bound(d[a].begin(),d[a].end(),b)-d[a].begin();
        if(idx!=d[a].size()){
            int cnt=d[a].size()-idx;
            while(cnt--){
                d[a].pop_back();
                ans++;
            }
        }
        if(d[a].empty()||(!d[a].empty()&&d[a].back()!=b)){
            d[a].push_back(b);
            ans++;
        }
    }
    cout<<ans;

}