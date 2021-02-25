#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> pf(n,0);
    vector<int> pb(n,0);
    for(int i=0;i<n;i++){
        cin>>pf[i];
    }
    for(int i=0;i<n;i++){
        cin>>pb[i];
        pb[i]+=pf[i];
    }

    int b=pf[0],idx=0,cnt=0,ans=-1;
    while(1){
        int mb=0;
        bool flag=false;
        while(idx<n&&pf[idx]<=b){
            flag=true;
            mb = max(mb,pb[idx]);
            idx++;
        }
        if(!flag)break;
        if(mb>=m){
            ans=cnt;
            break;
        }
        b = mb;
        cnt++;
    }
    cout<<ans;
}