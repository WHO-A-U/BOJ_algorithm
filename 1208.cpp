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

map<int,int> m1,m2;
vi v1,v2;
void combi(vi &v,map<int,int> &m){
    int n = v.size();
    for(int i=1;i<(1<<n);i++){
        int cm = i,val=0;
        for(int j=n-1;j>=0;j--){
            if(cm-(1<<j)>=0){
                cm-=(1<<j);
                val+=v[j];
            }
        }
        m[val]++;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,s,x;
    ll ans=0;
    cin>>n>>s;
    for(int i=0;i<n/2;i++){
        cin>>x;
        v1.push_back(x);
    }
    for(int i=0;i<n-n/2;i++){
        cin>>x;
        v2.push_back(x);
    }


    combi(v1,m1);
    combi(v2,m2);

    ans+=m1[s];
    ans+=m2[s];
    for(auto it = m1.begin();it!=m1.end();it++){
        int seqSum = it->first;
        int cnt = it->second;
        if(m2.find(s-seqSum)!=m2.end()){
            ans+=((ll)cnt*(ll)m2[s-seqSum]);
        }
    }
    cout<<ans;
}