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
vpii point;
int p[2001];
int find(int x){
    if(p[x]==x)
        return x;
    return p[x] = find(p[x]);
}
void Union(int a , int b){
    a = find(a);
    b = find(b);

    if(a!=b){
        p[b]=a;
    }
}
int getDist(pii a, pii b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
struct edge{
    int a;
    int b;
    int dist;
    edge(int x,int y,int z):a(x),b(y),dist(z){};

};
struct compare{
    bool operator()(struct edge a,struct edge b){
        return a.dist>b.dist;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,l,x,y;
    cin>>n>>l;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        point.emplace_back(x,y);
    }

    for(int i=0;i<n;i++){
        p[i]=i;
    }

    priority_queue <edge ,vector<edge>,compare> pq;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int dist = getDist(point[i],point[j]);
            if(dist>=l)
                pq.push({i,j,dist});
        }
    }

    int cnt=0;
    ll ans=0;
    while(!pq.empty()){
        auto t = pq.top();
        pq.pop();
        int a = t.a; 
        int b = t.b;
        int dist = t.dist;
        if(find(a)!=find(b)){
            ans+=dist;
            cnt++;
            Union(a,b);
        }
        if(cnt==n-1){
            break;
        }
    }
    if(cnt==n-1){
        cout<<ans;
    }else{
        cout<<"-1";
    }
}