#include <bits/stdc++.h>
using namespace std;
int d[300001];
int a[300001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }
    for(int i=2;i<=n;i++){
        d[i] = min(d[i],d[i-1]);
    }
    for(int i=0;i<m;i++){
        cin>>a[i];
    }

    int j=0,i=n;
    for(;i>=1&&j<m;i--){
        if(a[j]<=d[i]){
            j++;
        }
    }

    if(j==m)
        cout<<i+1;
    else
        cout<<0;
    
}