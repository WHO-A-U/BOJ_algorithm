#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using pii =pair<int,int>;
using vi = vector<int>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vb = vector<bool>;
vector<pair<int,pair<int,int> >> edge;
vpii d[3];
int p[100001];
int find(int cur){
    if(p[cur]==-1){
        return cur;
    }
    return p[cur]=find(p[cur]);
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x,y,z;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>x;
            d[j].push_back({x,i});
        }
    }

    for(int i=0;i<3;i++){
        sort(d[i].begin(),d[i].end());
    }

    for(int j=0;j<3;j++){
        for(int i=1;i<n;i++){
            auto [aVal,aIdx]=d[j][i];
            auto [bVal,bIdx]=d[j][i-1];
            int diff = aVal-bVal;
            edge.push_back({diff,{aIdx,bIdx}});
        }
    }

    sort(edge.begin(),edge.end());
    memset(p,-1,sizeof(p));

    long long ans=0;
    for(auto[cost,e] : edge){
        int a = e.first;
        int b = e.second;
        a = find(a);
        b = find(b);
        if(a!=b){
            p[a]=b;
            ans+=cost;
        }
    }
    cout<<ans;
}