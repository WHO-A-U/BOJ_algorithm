#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
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
vvll one = {{0LL,1LL},{1LL,1LL}};
vvll operator*(vvll a , vvll b){
    vvll ret(2,vll(2,0));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                ret[i][j] += a[i][k]*b[k][j];
            }
            ret[i][j]%=MOD;
        }
    }
    return ret;
}
vvll go(ll n ){
    if(n==1)
        return one;
    
    vvll half = go(n/2);
    half = half*half;
    if(n%2==1){
        half = half*one;
    }
    return half;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    auto p = go(n);
    cout<<p[1][0];
}