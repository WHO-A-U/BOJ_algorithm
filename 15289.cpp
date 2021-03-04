#include<iostream>
#include<cmath>
#define MOD 1234567891
using namespace std;
long long d[51];
int main(){
    d[0]=1;
    for(int i=1;i<51;i++){
        d[i]=d[i-1]*31%MOD;
    }

    int n;
    char c;
    cin>>n;
    long long ans=0;
    for(int i=0;i<n;i++){
        cin>>c;
        ans += (c-'a'+1)*d[i];
        ans%=MOD;
    }
    cout<<ans;
}