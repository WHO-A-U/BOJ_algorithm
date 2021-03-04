#include<iostream>
#include<algorithm>
using namespace std;
int d[501][501];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,b;
    cin>>n>>m>>b;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>d[i][j];
        }
    }
    int minTime = 0x3f3f3f3f;
    int ans;
    for(int k=0;k<=256;k++){
        int cost=0;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(d[i][j]>k){
                    cost+=(d[i][j]-k)*2;
                    cnt1+=(d[i][j]-k);
                }
                if(d[i][j]<k){
                    cnt2+=(k-d[i][j]);
                    cost+=(k-d[i][j]);

                }
            }
        }
        if(cnt1+b<cnt2)continue;
        if(minTime>=cost){
            minTime=cost;
            ans=k;
        }
    }
    cout<<minTime<<" "<<ans;
}