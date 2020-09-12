#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
ll jewelry[300001];
ll n,m,x,maxJ=0;
bool isPossible(int jealous){
    ll cnt=0;
    for(int i=0;i<m;i++){
        cnt+=jewelry[i]/jealous;
        if(jewelry[i]%jealous>0)
            cnt++;
    }
    return cnt<=n;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>jewelry[i];
        maxJ=max(maxJ,jewelry[i]);
    }
    ll l=0,r=maxJ,mid,ans;
    while(l<=r){
        mid=(l+r)/2;
        if(isPossible(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans;

}