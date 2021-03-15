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

int d[1025][11];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(d,0,sizeof(d));

        string s;
        for(int i=1;i<=n;i++){
            cin>>s;
            for(int j=0;j<(1<<m);j++){
                
                bool flag=true;
                for(int k=0;k<m;k++){
                    if(j&(1<<k)){
                        if(s[k]=='x'){
                            flag=false;
                            break;
                        }
                    }
                }
                if(!flag){
                    continue;
                }
                for(int k=1;k<m;k++){
                    if((j&(1<<k))>0&&(j&(1<<(k-1)))>0){
                        flag=false;
                        break;
                    }
                }
                if(!flag){
                    continue;
                }

                int cnt=0;
                for(int k=0;k<m;k++){
                    if((j&(1<<k))&&(s[k]=='.')){
                        cnt++;
                    }
                }

                for(int k=0;k<(1<<m);k++){
                    int flag2=true;
                    for(int z=0;z<m;z++){
                        if(j&(1<<z)){
                            if(z-1>=0 && (k&((1<<(z-1))))){
                                flag2=false;
                                break;
                            }
                            if(z+1<m && (k&(1<<(z+1)))){
                                flag2=false;
                                break;
                            }
                        }
                    }
                    if(flag2)
                        d[j][i]=max(d[j][i],d[k][i-1]);
                }
                d[j][i]+=cnt;
            }
        }
        int ans=0;
        for(int i=0;i<(1<<m);i++){
            ans = max(ans , d[i][n]);
        }
        cout<<ans<<"\n";
    }
}