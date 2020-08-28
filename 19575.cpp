#include<iostream>
#define MOD 1000000007
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long ans=0,n,k,coe,deg;
    cin>>n>>k;
    for(int i=0;i<=n;i++){
        ans=(ans*k)%MOD;
        cin>>coe>>deg;
        ans+=coe;
    }
    cout<<ans%MOD;
}