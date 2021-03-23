#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
using namespace std;
using pii = pair<int, int>;
using vpii = vector<pii>;

vpii edge[5001];
int d[5001][5001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,a,b,c;
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        cin>>a>>b>>c;
        edge[a].emplace_back(b,c);
        edge[b].emplace_back(a,c);
    }
    bool visit[5001];

    queue<pii> q;
    for(int i=1;i<=n;i++){
        q.push({i,0});

        memset(visit,false,sizeof(visit));
        
        visit[i]=true;

        while(!q.empty()){
            int cur = q.front().first;
            int usado = q.front().second;
            q.pop();

            for(auto x: edge[cur]){
                int next = x.first;
                if(!visit[next]){
                    int minVal;
                    if(usado == 0) minVal = x.second;
                    else minVal = min(usado,x.second);
                    d[i][next] = minVal;
                    visit[next]=true;
                    q.push({next,minVal});
                }
            }
        }
    }

    while(m--){
        cin>>a>>b;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a<=d[b][i])
                ans++;
        }
        cout<<ans<<"\n";
    }

    

}