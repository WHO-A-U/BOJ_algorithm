#include <cstdio>
#include<iostream>
#include <cstring>
using namespace std;
const int MAX = 500001;
const int MAX_D = 19;
int d[MAX][MAX_D];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n,x,q;
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>d[i][0];
    }

    for(int i=1;i<MAX_D;i++){
        for(int j=1;j<=m;j++){
            d[j][i]=d[d[j][i-1]][i-1];
        }
    }
    
    cin>>q;
    while(q--){
        cin>>n>>x;
        for(int i=MAX_D;i>=0;i--){
            if((n&(1<<i))>0){
                n-=(1<<i);
                x = d[x][i];
            }
        }
        cout<<x<<"\n";
    }
    
}

