#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
#define MOD 1'000'000'007
using namespace std;
using ll = long long;
map<ll,ll> factors;
ll getPow(ll num , ll exp){
    if(exp==0){
        return 1;
    }
    ll n = getPow(num,exp/2)%MOD;
    ll ret = ((n%MOD)*(n%MOD))%MOD;
    if(exp%2==1){
        return (num*ret)%MOD;
    }
    return ret%MOD;
}
tuple<ll, ll, ll> xGCD(ll a, ll b) {
      if (b == 0)
          return make_tuple(a, 1, 0);
      ll g, x, y;
      tie(g, x, y) = xGCD(b, a%b);
      return make_tuple(g, y, x-(a/b)*y);
}
ll foo(ll x){
    while(x<=0){
        x+=MOD;
    }
    return x%MOD;
}
ll getSeries(ll p , ll k){
    ll d=(getPow(p,k+1)-1+MOD)%MOD;
    auto f = (xGCD(p-1,MOD));
    ll n=foo(get<1>(f));
    return ((d%MOD) * (n%MOD))%MOD;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;
    cin>>n>>m;
    ll d = n;
    for(ll i=2;i*i<=d;i++){
        while(d%i==0){
            factors[i]++;
            d/=i;
        }
    }
    if(d>1)
        factors[d]++;
    
    ll ans=1;
    for(auto it = factors.begin();it!=factors.end();it++){
        ll p = it->first;
        ll k = it->second;
        ans*=getSeries(p,k*m);
        ans%=MOD;
    }
    cout<<ans;
}