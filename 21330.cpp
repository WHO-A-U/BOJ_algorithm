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

int n;
vi d;
int dp[301][301];
int go(int l , int r){
    if(l==r)
        return 0;
    int &ret = dp[l][r];
    if(ret!=-1){
        return ret;
    }
    ret = INF;
    for(int i=l;i<r;i++){
        ret = min(ret , (d[l]!=d[i+1])+go(l,i)+go(i+1,r));
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp,-1,sizeof(dp));
    cin>>n;
    int x,prev=-1;
    for(int i=0;i<n;i++){
        cin>>x;
        if(prev!=x){
            d.push_back(x);
            prev = x;
        }
    }
    if(d.size()==1 && d[0]==1){
        return 0;
    }
    cout<<go(0,d.size()-1)+1;
}