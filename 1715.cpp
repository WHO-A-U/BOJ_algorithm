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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<n;i++){
        cin>>x;
        q.push(x);
    }
    int ans=0;
    while(q.size()>1){
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        ans+=(a+b);
        q.push(a+b);
    }
    cout<<ans;
}