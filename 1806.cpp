#include<iostream>
#include<algorithm>
using namespace std;
long long d[100001];
int main(){
    int n,s;
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }
    int mlen=0x3f3f3f;
    int j=1;
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans+=d[i];
        if(ans>=s){
            while(ans-d[j]>=s&&j<i){
                ans-=d[j];
                j++;
            }
            mlen=min(mlen,i-j+1);
        }
    }
    cout<<(mlen==0x3f3f3f?0:mlen);
}