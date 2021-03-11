#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<cmath>
#include<set>
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vs = vector<string>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vvi = vector<vi>;
vi cost;
vvi edge;
vb visit;
int n,m,k,x,y,cnt;
void go(int cur){
    if(visit[cur]){
        return ;
    }
    visit[cur]=true;
    cnt++;
    for(int next : edge[cur]){
        if(!visit[next]){
            go(next);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m>>k;

    cost.assign(n+1,0);
    edge.assign(n+1,vi());
    visit.assign(n+1,false);

    priority_queue<pii,vpii,greater<pii>> pq;

    for(int i=1;i<=n;i++){
        cin>>cost[i];
        pq.push({cost[i],i});
    }

    for(int i=0;i<m;i++){
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    int minCost=0;
    for(int i=1;i<=n;i++){
        int c = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        if(visit[idx])continue;
        if(c>k){
            break;
        }
        k-=c;
        minCost+=c;
        go(idx);

        if(cnt==n)break;
    }

    if(cnt==n){
        cout<<minCost;
    }else{
        cout<<"Oh no";
    }
}

