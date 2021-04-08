#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int, int>;
using vpii = vector<pii>;

vpii e[1001];
int dist[1001][1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,p,k,a,b,c;
    cin>>n>>p>>k;
    for(int i=0;i<p;i++){
        cin>>a>>b>>c;
        e[a].push_back({b,c});
        e[b].push_back({a,c});
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            dist[i][j]=INF;
        }
    }

    queue<pii> q;
    q.push({1,0});
    dist[1][0]=0;
    while(!q.empty()){
        int cur = q.front().first;
        int Kcnt = q.front().second;
        int curCost = dist[cur][Kcnt];
        q.pop();
        for(auto x : e[cur]){
            int next = x.first;
            int cost = x.second;
            if( dist[next][Kcnt]>max(curCost,cost) ){
                dist[next][Kcnt] = max(curCost,cost);
                q.push({next,Kcnt});
            }
            if(Kcnt<k && dist[next][Kcnt+1]>curCost ){
                dist[next][Kcnt+1] = curCost;
                q.push({next,Kcnt+1});
            }
        }
    }

    if(dist[n][k]==INF){
        cout<<"-1";
    }else{
        cout<<dist[n][k];
    }

}