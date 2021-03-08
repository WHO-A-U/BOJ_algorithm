#include<iostream>
#include<algorithm>
using namespace std;
int d[1025][1025];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,x1,x2,y1,y2;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>d[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[i][j]+=d[i][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[i][j]+=d[i-1][j];
        }
    }
    while(m--){
        cin>>x1>>x2>>y1>>y2;
        cout<<d[y1][y2]-d[x1-1][y2]-d[y1][x2-1]+d[x1-1][x2-1]<<"\n";
    }
}

