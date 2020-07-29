#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
vector<pair<int,int>> home;
vector<pair<int,int>> store;
vector<int> choose;
int n,m,x;
int ans=0x3f3f3f3f;
void verify(){
    int citydst=0;
    for(int i=0;i<home.size();i++){
        int hr = home[i].first;
        int hc = home[i].second;
        int minval =0x3f3f3f3f;
        for(int j=0;j<choose.size();j++){
            int sr = store[choose[j]].first;
            int sc = store[choose[j]].second;
            minval=min(minval,abs(hr-sr)+abs(hc-sc));
        }
        citydst+=minval;
    }
    ans=min(ans,citydst);
}
void go(int cnt){
    if(cnt>store.size())
        return ;
    if(choose.size()==m){
        //backtracking end point
        verify();
        return ;
    }
    choose.push_back(cnt);
    go(cnt+1);
    choose.pop_back();
    go(cnt+1);
    return ;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>x;
            if(x==1){
                home.push_back({i,j});
            }
            if(x==2){
                store.push_back({i,j});
            }
        }
    }
    go(0);
    cout<<ans;
}