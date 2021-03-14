#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
#define MAX 40001
#define MAX_D 17
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
vpii edge[MAX];

int d[MAX][MAX_D]; //0  node
int cost[MAX][MAX_D]; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,x,y,c;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>x>>y>>c;
        edge[x].emplace_back(y,c);
        edge[y].emplace_back(x,c);
    }

    queue<int> q;
    q.push(1);

    vb v(n+1);
    vi level(n+1);

    v[1]=true;
    level[1]=1;

    while(!q.empty()){
        int cur = q.front();
        int depth = level[cur];

        q.pop();
        for(auto e : edge[cur]){

            int next = e.first;
            int ncost = e.second;

            if(!v[next]){

                q.push(next);
                level[next]=depth+1;
                v[next]=true;

            }else{
                d[cur][0]=next;
                cost[cur][0]=ncost;
            }
        }
    }

    d[1][0]=1;

    for(int j=1;j<MAX_D;j++){
        for(int i=1;i<=n;i++){
            d[i][j] = d[d[i][j-1]][j-1];
            cost[i][j] = cost[d[i][j-1]][j-1]+cost[i][j-1];
        }
    }


    cin>>m;

    int a,b;
    while(m--){
        cin>>a>>b;
        if(level[a]>level[b]){
            swap(a,b);  
        }
        int ans=0;
            //b의 레벨이 더 큼
        int diff = level[b]-level[a];
        for(int j=MAX_D-1;j>=0;j--){
            if(diff-(1<<j)>=0){
                ans+=cost[b][j];
                diff -=(1<<j);
                b = d[b][j];
            }
        }

        for(int j=MAX_D-1;j>=0;j--){
            if(d[a][j]!=d[b][j]){
                ans+=(cost[a][j]+cost[b][j]);
                a=d[a][j];
                b=d[b][j];
            }
        }

        if(a!=b){
            ans+=(cost[a][0]+cost[b][0]);
        }
        cout<<ans<<"\n";
    }

}