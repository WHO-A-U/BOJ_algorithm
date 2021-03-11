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
int d[1000][3];
int dp[10001][3];
void init(int n){
    for(int i=0;i<n;i++){
        dp[i][0]=dp[i][1]=dp[i][2]=INF;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,ans=INF;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>d[i][0]>>d[i][1]>>d[i][2];
    }

    for(int k=0;k<3;k++){
        //rgb 0123
        init(n);
        dp[0][k]=d[0][k];
        for(int i=1;i<n;i++){
            for(int j=0;j<3;j++){
                dp[i][j] = min(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3])+d[i][j];
            }
        }

        for(int i=0;i<3;i++){
            if(i!=k){
                ans = min(ans , dp[n-1][i]);
            }
        }
    }

    cout<<ans;
}