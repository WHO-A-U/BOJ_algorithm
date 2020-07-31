#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    int n,t,x,ans=0;
    cin>>n>>t;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    for(int i=n-1;i>=0;i--){
        if(t>=v[i]){
            ans+=t/v[i];
            t%=v[i];
        }
    }
    cout<<ans;
}