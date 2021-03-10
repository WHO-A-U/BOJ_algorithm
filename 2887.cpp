#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using pii =pair<int,int>;
using vi = vector<int>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vb = vector<bool>;
vpii d[3];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x,y,z;
    cin>>n;
    vvpii edge(n);
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
            edge[aIdx].push_back({bIdx,diff});
            edge[bIdx].push_back({aIdx,diff});
        }
    }

    priority_queue<pii,vector<pii>,greater<pii>> pq;


    while(!pq.empty()){
        printf("%d %d\n",pq.top().first,pq.top().second);
        pq.pop();
    }

    vb visit(n,false);
    vi dist(n,INF);
    int cur = 0;
    visit[cur]=true;
    long long ans=0;
    for(int i=0;i<n-1;i++){

        for(auto [idx,cost] : edge[cur]){
            if(!visit[idx] && dist[idx]>cost){
                pq.push({cost,idx});
            }
        }
        
        while(!pq.empty()){
            auto [cost , next] = pq.top();
            pq.pop();
            if(!visit[next]){
                visit[next]=true;
                ans+=cost;
                cur = next;
                break;
            }
        }
    }
    
    cout<<ans;
}




