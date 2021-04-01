#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
#define MOD 1'000'000'007
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
ll get(ll num,ll pow){
    if(pow==1){
        return num;
    }
    ll half = get(num,pow/2);
    half = (half*half)%MOD;
    if(pow&1){
        half=(half*num)%MOD;
    }
    return half;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin>>m;
    ll ans=0,b,a;
    while(m--){
        cin>>b>>a;
        //a * b^1000000005
        ll GCD = __gcd(a,b);
        a/=GCD;
        b/=GCD;
        ans+=(a*(get(b,MOD-2)));
        ans%=MOD;
    }
    cout<<ans;
}