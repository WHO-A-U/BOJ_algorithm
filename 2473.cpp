#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define ll long long 
using namespace std;
vector<ll> num;
vector<bool> sel;
vector<ll> ans;
ll minval=0x7f7f7f7f7f7f7f;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ll x;
    cin>>n;
    sel.assign(n,false);
    for(int i=0;i<n;i++){
        cin>>x;
        num.push_back(x);
    }
    sort(num.begin(),num.end());
    for(int i=0;i<n;i++){
        sel[i]=true;
        int l=0,r=n-1;
        while(l<r){
            if(sel[l]){
                l++;
                continue;
            }
            if(sel[r]){
                r--;
                continue;
            }
            ll cur = num[i]+num[l]+num[r];
            if(abs(cur)<minval){
                minval = abs(cur);
                ans.clear();
                ans.push_back(num[i]);
                ans.push_back(num[l]);
                ans.push_back(num[r]);
            }
            if(cur<0)
                l++;
            else{
                r--;
            }
        }
        sel[i]=false;
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<3;i++){
        cout<<ans[i]<<" ";
    }
    
}