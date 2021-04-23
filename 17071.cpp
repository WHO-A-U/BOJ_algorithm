#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
#define MAX 500'001
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
int n,k,ans=INF;
int m[MAX];
bool v[MAX][2];
bool isValid(int idx){
    return idx>=0&&idx<MAX;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(m,-1,sizeof(m));
    memset(v,false,sizeof(v));

    cin>>n>>k;
    int delta=0,cur=k;

    while(cur<MAX){
        m[cur] = delta++;
        cur+=delta;
    }

    queue<pii> q;
    q.push({n,0});

    v[n][0]=true;
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        
        if(m[cur]>=0 && m[cur]>=cnt && (m[cur]-cnt)%2==0)
            ans = min(ans , m[cur]);
        
        q.pop();

        if(isValid(cur+1)&&!v[cur+1][cnt%2]){
            v[cur+1][cnt%2]=true;
            q.push({cur+1,cnt+1});
        }
        if(isValid(cur-1) && !v[cur-1][cnt%2]){
            v[cur-1][cnt%2] = true;
            q.push({cur-1,cnt+1});
        }
        if(isValid(cur*2) && !v[cur*2][cnt%2]){
            v[cur*2][cnt%2]=true;
            q.push({cur*2,cnt+1});
        }        
    }

    if(ans==INF)
        cout<<"-1";
    else
        cout<<ans;
    
    return 0;
}