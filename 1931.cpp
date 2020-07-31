#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
bool func(pair<int,int> &a, pair<int,int>&b){
    if(a.second<b.second)
        return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b;
    vector<pair<int,int>> v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    sort(v.begin(),v.end(),func);
    int ans=1,time=v[0].second;
    for(int i=1;i<n;i++){
        if(time<=v[i].first){
            time=v[i].second;
            ans++;
        }
    }
    cout<<ans;
}