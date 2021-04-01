#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vs = vector<string>;
using vd = vector<double>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vvpii = vector<vpii>;
using vvpll = vector<vpll>;
using vvs = vector<vs>;

int d[111];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    int from,to;
    cin>>n>>m;
    for(int i=1;i<=100;i++){
        d[i]=i;
    }
    for(int i=0;i<n;i++){
        cin>>from>>to;
        d[from]=to;
    }
    for(int i=0;i<m;i++){
        cin>>from>>to;
        d[from]=to;
    }
    queue<int> q;
    q.push(1);
    vi dist(101,INF);
    dist[1]=0;
    int ans=0,cur=1;
    while(!q.empty()){
        int cur = q.front();
        int curDist=dist[cur];
        q.pop();

        
        for(int i=1;i<7;i++){
            int next = d[cur+i];
            if(next>=1&&next<=100&&dist[next]>curDist+1){
                dist[next]=curDist+1;
                q.push(next);
            }
        }
    }
    cout<<dist[100];

}