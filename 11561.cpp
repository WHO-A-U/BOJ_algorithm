#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPossible(long long mid,long long n){
    // printf("N : %lld\n",mid*(mid+1)/2);
    if((mid*(mid+1))/2<=n)return true;
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long l=0,r=1000000000,mid,ans;
        while(l<=r){
            mid = (l+r)/2;
            // printf("mid : %lld l : %lld r : %lld\n",mid,l,r);
            if(isPossible(mid,n)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        cout<<ans<<'\n';
    }
}