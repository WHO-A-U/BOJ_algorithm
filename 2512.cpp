#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> city;
long long  totalsum(int n){
    long long val=0;
    for(int i=0;i<city.size();i++)
    {
        if(city[i]>=n)
            val+=n;
        else
            val+=city[i];
    }
    return val;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T,x,maxC=0;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>x;
        maxC=max(maxC,x);
        city.push_back(x);
    }
    int maxbudget;
    cin>>maxbudget;
    int l=0,r=maxC;
    long long mid,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        long long subtotal=totalsum(mid);
        if(subtotal>maxbudget){
            r=mid-1;
        }
        else{
            l=mid+1;
            ans=max(ans,mid);
        }
    }
    cout<<ans;
}