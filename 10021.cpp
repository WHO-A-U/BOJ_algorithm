#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f
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

ll d[2001][2001];
vpii p;
ll getDist(pii a , pii b){
    return (((ll)(a.first-b.first)*(a.first-b.first))+((ll)(a.second-b.second)*(a.second-b.second)));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x,y;
    ll l;
    cin>>n>>l;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        p.emplace_back(x,y);
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d[i][j]=INF;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll dist = getDist(p[i],p[j]);
            if(dist>=l)
                d[i][j] = d[j][i] =  dist;
        }
    }

    bool visit[2001];
    ll cost[2001];
    memset(visit,false,sizeof(visit));

    for(int i=0;i<n;i++){
        cost[i] = INF;
    }

    ll ans=0;
    queue<int> q;

    q.push(0);
    cost[0]=0;
    visit[0]=true;
    bool isFail=false;
    int cnt=n-1;
    while(cnt--){
        int cur = q.front();
        q.pop();
        for(int i=0;i<n;i++){
            ll nextCost =d[cur][i];
            if(!visit[i]&&(nextCost<cost[i])){
                cost[i] = nextCost;
            }
        }

        ll minVal=INF;
        int idx;

        for(int i=0;i<n;i++){
            if(!visit[i]){
                if(minVal>cost[i]){
                    minVal=cost[i];
                    idx=i;
                }
            }
        }


        if(minVal==INF){
            isFail=true;
            break;
        }

        ans+=minVal;
        visit[idx]=true;
        q.push(idx);
    }
    if(isFail){
        cout<<-1;
    }else{
        cout<<ans;
    }


}