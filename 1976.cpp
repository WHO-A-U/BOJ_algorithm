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

int d[201][201];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,x;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];
        }
        d[i][i]=1;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                d[i][j] = (d[i][k]+d[k][j]>=2)?1:d[i][j];
            }
        }
    }
    vi route;
    while(m--){
        cin>>x;
        route.push_back(x-1);
    }

    for(int i=1;i<route.size();i++){
        if(d[route[i-1]][route[i]]==0){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}