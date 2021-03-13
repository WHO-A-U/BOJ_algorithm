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

int d[10001][2];
int dp[10001][3];
void init(int n){
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            dp[i][j]=INF;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n,w;
    cin>>t;
    while(t--){
        cin>>n>>w;
        for(int j=0;j<2;j++){
            for(int i=1;i<=n;i++){
                cin>>d[i][j];
            }
        }

        
        vi rot;
        rot.push_back(2); //첨부터쭉 끝까지
        if(d[1][0]+d[n][0]<=w)rot.push_back(1); //상단 1 n합병
        if(d[1][1]+d[n][1]<=w)rot.push_back(0); //하단 1 n합병
        if(d[1][0]+d[n][0]<=w&&d[1][1]+d[n][1]<=w)rot.push_back(-1); //둘다 합병

        int ans=INF;
        for(auto mode : rot){

            init(n);
            dp[0][0]=dp[0][1]=dp[0][2]=0;

            for(int i=1;i<=n;i++){
                
                if(!(i==1&&(mode==1||mode==-1))){
                    dp[i][0]= min(dp[i][0],dp[i-1][2]+1);
                    if(d[i-1][0]+d[i][0]<=w){
                        dp[i][0]=min(dp[i][0],dp[i-1][1]+1);
                    }
                }else{
                    dp[i][0]=0;
                }

                if(!(i==1&&(mode==0||mode==-1))){

                    dp[i][1]= min(dp[i][1],dp[i-1][2]+1);

                    if(d[i-1][1]+d[i][1]<=w){
                        dp[i][1]=min(dp[i][1],dp[i-1][0]+1);
                    }

                }else{
                    dp[i][1]=0;
                }

                if(!(i==1&&(mode==-1))){

                    dp[i][2] = min({dp[i][0]+1,dp[i][1]+1,dp[i][2]});

                    if(d[i][0]+d[i][1]<=w){
                        dp[i][2] = min(dp[i-1][2]+1,dp[i][2]);
                    }

                    if(d[i-1][0]+d[i][0]<=w && d[i-1][1]+d[i][1]<=w && i-2>=0){
                        dp[i][2]= min(dp[i-2][2]+2,dp[i][2]);
                    }

                }else{
                    dp[i][2]=0;
                }

            }


            if(mode==2)
                ans = min(ans , dp[n][2]);
            if(mode==1||mode==0)
                ans = min(ans , dp[n][mode]+1);
            if(mode==-1)
                ans = min(ans , dp[n-1][2]+2);
            
            
        }
        cout<<ans<<"\n";
    }
}