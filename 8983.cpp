#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int> saro;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n,L,y,x,ans=0;
    cin>>m>>n>>L;
    for(int i=0;i<m;i++){
        cin>>x;
        saro.push_back(x);
    }
    sort(saro.begin(),saro.end());
    for(int i=0;i<n;i++){
        cin>>x>>y;
        int minx = lower_bound(saro.begin(),saro.end(),x)-saro.begin();
        int l=0,r=saro.size()-1,mid,tmp=0;
        while(l<=r){
            mid=(l+r)/2;
            if(saro[mid]>x){
                r=mid-1;
            }
            else{
                tmp=mid;
                l=mid+1;
            }
        }
        // cout<<"tmp:"<<tmp<<endl;
        int nleft = saro[tmp];
        int nright = saro[minx];
        if(min(abs(x-nleft),abs(nright-x))+y<=L)
            ans++;
    }
    cout<<ans;
}