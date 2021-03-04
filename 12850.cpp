#include<iostream>
#include<vector>
#define mod 1000000007
using namespace std;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
long long d[100001][9];
vvll p = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 1, 0}
};
vvll multi(vvll &a , vvll &b){
    vvll ret;
    for(int i=0;i<8;i++){
        vll r;
        for(int j=0;j<8;j++){
            ll tmp=0;
            for(int k=0;k<8;k++){
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
    vvll ans=p;
    int n;
    cin>>n;
    n--;
    while(n>0){
        if(n%2==1){
            ans = multi(ans,p);
        }
        p = multi(p,p);
        n/=2;
    }
    cout<<ans[0][0];
    
}