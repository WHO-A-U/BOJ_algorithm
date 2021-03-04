#include<iostream>
#include<vector>
#define mod 1000000007
using namespace std;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
int n,m;

vvll multi(vvll &a , vvll &b){
    vvll ret;
    for(int i=0;i<n;i++){
        vll r;
        for(int j=0;j<n;j++){
            ll tmp=0;
            for(int k=0;k<n;k++){
                tmp+=(a[i][k]*b[k][j]);
                tmp%=mod;
            }
            r.push_back(tmp);
        }
        ret.push_back(r);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    int x,y,d;
    vvll p(n,vll(n));
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--;
        y--;
        p[x][y]=p[y][x]=1;
    }
    vvll ans=p;
    cin>>d;
    d--;
    while(d>0){
        if(d%2==1){
            ans = multi(ans,p);
        }
        p = multi(p,p);
        d/=2;
    }
    cout<<ans[0][0];
    
}