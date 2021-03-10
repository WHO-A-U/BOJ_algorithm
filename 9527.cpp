#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
ll getBitNum(ll x){
    if(x==0)return 0;
    return 1+((x/2)*(ll)floor(log2(x)));
}
ll getBitSum(ll x){

    if(x<=0)return 0;

    string bit="";
    while(x!=0){
        bit = ((x%2==1)?"1":"0")+bit;
        x/=2;
    }
    
    int len = bit.length()-1,cnt=0;
    ll ret=0;

    for(int i=0;i<bit.length();i++){
        if(bit[i]=='1'){
            ret+=(1LL<<(len-i))*cnt;
            ret+=getBitNum((1LL<<(len-i)));
            cnt++;
        }
    }
    return ret;
}
int main(){
    ll a,b;
    cin>>a>>b;
    cout<<getBitSum(b)-getBitSum(a-1);
}