#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int getPercent(long long x,long long y){
    return ((double)y*100/(double)x);
}
int main(){
    long long x,y;
    cin>>x>>y;
    double cur =  getPercent(x,y);
    if(cur>=99){
        cout<<"-1";
        return 0;
    }
    long long l=0,r=2,mid;
    while(l<r){
        mid=(l+r)/2;
        int target = getPercent(mid+x,mid+y);
        if(target-cur>=1){
            r=mid;
        } else{
            l=mid+1;
            r=r*2;
        }
    }
    cout<<r;
}