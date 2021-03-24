#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;

vi p[200001];
int sell[200001];
pii go(int cur){
    if(p[cur].size()==0)
        return {0,0};
    vpii v;

    int firstMax = 0,secondMax = 0;
    for(auto x: p[cur]){
        v.push_back(go(x)); 
        secondMax+=max(v.back().first,v.back().second);
    }
    for(int i=0;i<v.size();i++){
        if(v[i].first > v[i].second)
            firstMax = max(firstMax , secondMax -v[i].first+v[i].second + sell[cur]*sell[p[cur][i]]);
        else{
            firstMax = max(firstMax , secondMax + sell[cur]*sell[p[cur][i]]);
        }
    }
    return {firstMax,secondMax};
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin>>n;

    for(int i=2;i<=n;i++){
        cin>>x;
        p[x].push_back(i);
    }

    for(int i=1;i<=n;i++){
        cin>>sell[i];
    }

    auto ans = go(1);
    cout<<max(ans.first,ans.second);
}