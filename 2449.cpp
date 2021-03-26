#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
using namespace std;
using vi = vector<int>;

vi d;
int n,k;
int dp[201][201];
int go(int l,int r){
    if(l>=r)return 0;

    int &ret = dp[l][r];
    if(ret!=-1)
        return ret;
    
    ret=INF;
    if(l==r)
        ret  =  0;
    for(int i=l;i<r;i++)
        ret = min(ret ,(d[l]!=d[i+1]?1:0)+go(l,i)+go(i+1,r));

    return ret;    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp,-1,sizeof(dp));
    int x,prev=-1;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x;
        if(prev!=x){
            d.push_back(x);
            prev = x;
        }
    }
    cout<<go(0,d.size()-1);
}