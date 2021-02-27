#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,prev,x;
    cin>>n;
    vector<int> d(n,0);
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    int idx=-1;
    for(int i=0;i<n-1;i++){
        if(d[i]>d[i+1]){
            idx=i;
        }
    }
    if(idx==-1){
        cout<<"-1";
        return 0;
    }
    int m=0;
    for(int i=idx+1;i<n;i++){
        if(d[idx]>d[i])
            m = max(m,d[i]);
    }
    vector<int> a;
    for(int i=idx;i<n;i++){
        if(d[i]!=m)
            a.push_back(d[i]);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for(int i=0;i<idx;i++){
        cout<<d[i]<<" ";
    }
    cout<<m<<" ";
    for(int x : a){
        cout<<x<<" ";
    }

}