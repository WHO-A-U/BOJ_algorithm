#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000003
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using vll = vector<ll>;
using matrix = vector<vll>;
matrix operator * (const matrix &a , const matrix &b){
    int n = a.size();
    matrix ret(n,vll(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                ret[i][j]+=a[i][k]*b[k][j];
            }
            ret[i][j]%=MOD;
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,s,e,t;
    cin>>n>>s>>e>>t;
    s--,e--;
    matrix map(5*n+1,vll(5*n+1));
    matrix ans(5*n+1,vll(5*n+1));


    string str;

    for(int i=0;i<n;i++){
        cin>>str;
        for(int j=0;j<n;j++){
            int cur = str[j]-'0';
            if(cur>0){
                map[5*i+cur-1][5*j]=1;
            }
        }
        for(int j=0;j<4;j++){
            map[5*i+j][5*i+j+1]=1;
        }
    }

    if(t>0){
        ans = map;
        t--;
    }

    while(t>0){
        if(t&1){
            ans = ans*map;
        }
        map  = map * map;
        t>>=1;
    }


    cout<<ans[s*5][e*5];

}




