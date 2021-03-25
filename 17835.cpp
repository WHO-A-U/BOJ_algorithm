#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vpii = vector<pii>;

vpii edge[100001];
ll d[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>b>>a>>c;
        edge[a].push_back({b,c});
    }

    for(int i=1;i<=n;i++){
        d[i]=INF;
    }

    queue<int> q;
    for(int i=0;i<k;i++){
        cin>>a;
        q.push(a);
        d[a]=0;
    }
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto x : edge[cur]){
            int next = x.first;
            int cost = x.second;
            ll minCost = cost+d[cur];
            if(minCost<d[next]){
                d[next]=minCost;
                q.push(next);
            }
        }
    }

    int idx;
    ll maxVal=-1;
    for(int i=1;i<=n;i++){
        if(maxVal<d[i]){
            maxVal=d[i];
            idx=i;
        }
    }
    cout<<idx<<"\n"<<maxVal;
    
    
}