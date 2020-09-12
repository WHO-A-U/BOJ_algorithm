#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
vector<long long> time;
long long n,m,x;
bool isPossible(long long t){
    long long cnt=0;
    for(int i=0;i<n;i++){
        cnt+=(t/time[i]);
    }
    return cnt>=m;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    long long maxtime=0;
    for(int i=0;i<n;i++){
        cin>>x;
        maxtime=max(maxtime,x);
        time.push_back(x);
    }
    unsigned long long l=1,r=m*maxtime,mid,ans;
    while(l<=r){
        mid=(l+r)/2;
        // cout<<mid<<" ";
        if(isPossible(mid)){
            // cout<<"!";
            ans=mid;
            r=mid-1;
        }else{
            // cout<<"@";
            l=mid+1;
        }
    }
    cout<<ans;
}