#include <bits/stdc++.h>
using namespace std;
int d[200001][3]; //0 : val , 1 : maxInitVal 2 : minWinVal;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>d[i][0];
    }
    if(n==1){
        cout<<"1";
        return 0;
    }

    for(int i=1;i<n;i++){
        if(d[i][0]>d[i-1][0]){
            d[i][1] = i+d[i][0];
        }
    }

    d[n-1][2] = d[n-1][0];
    for(int i=n-2;i>=0;i--){
        d[i][2] = max(d[i+1][2]-1,d[i+1][0]+1);
    }
    
    bool flag=false;
    for(int i=0;i<n;i++){
        if(d[i][1]>0&&d[i][2]>0&&d[i][1]>=d[i][2]){
            flag=true;
            cout<<i+1<<" ";
        }
    }
    if(!flag){
        cout<<"-1";
    }
}