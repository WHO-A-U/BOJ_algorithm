#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
using ll = long long ;
using pll = pair<ll,ll>;
using vpll = vector<pll>;
ll answer;
vpll point;
ll getCcw(pll a , pll b , pll c){
    ll x = (b.first-a.first)*(c.second-a.second);
    ll y = (b.second-a.second)*(c.first-a.first);
    return x-y;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,x,y;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        point.emplace_back(x,y);
    }

    auto cur = point[0];
    for(int i=1;i<point.size()-1;i++){
        answer += getCcw(cur,point[i],point[i+1]);
    }
    answer = abs(answer);

    cout<<answer/2;
    if(answer%2==1){
        cout<<".5";
    }else{
        cout<<".0";
    }
}