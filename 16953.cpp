#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long ;
int main(){
    ll a,b;
    cin>>a>>b;
    int ans=INF;
    queue<pair<ll,int>> q;
    q.push({a,0});
    while(!q.empty()){
        ll cur = q.front().first;
        int cost = q.front().second;
        q.pop();

        if(cur==b){
            ans = min(ans , cost);
            continue;
        }
        if(cur*2<=b){
            q.push({cur*2,cost+1});
        }
        if(cur*10+1<=b){
            q.push({cur*10+1,cost+1});
        }
    }
    if(ans!=INF){
        cout<<ans+1;
    }else{
        cout<<"-1";
    }
}