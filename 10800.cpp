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

int total,n,c,v;;
int sum[200001];
int color[200001];
int valCnt[2001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n;
    vpii d;

    for(int i=0;i<n;i++){
        cin>>color[i]>>v;
        d.emplace_back(v,i);
    }

    sort(all(d),[&](const auto &a , const auto &b){
        if(a.first<b.first)return true;
        if(a.first>b.first)return false;
        if(color[a.second]<color[b.second])return true;
        return false;
    });

    vi ans(n);
    int curVal = d[0].first;
    int idx = d[0].second;
    int same=0;
    for(auto cur : d){
        if(curVal!=cur.first||color[idx]!=color[cur.second]){
            sum[color[idx]]+=same*curVal;
            same=0;

            curVal = cur.first;
            idx = cur.second;
        }
        idx = cur.second;

        total+=curVal;
        valCnt[curVal]++;
        ans[idx] = total-sum[color[idx]]-(valCnt[curVal])*curVal;
        same++;
    }

    for(int x : ans){
        cout<<x<<"\n";
    }

}