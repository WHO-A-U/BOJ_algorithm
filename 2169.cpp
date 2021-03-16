#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;

    vvi d(n+1,vi(m+2));
    vvi l=d,r=d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>d[i][j];
        }
    }

    for(int i=2;i<=m;i++)
        d[1][i]+=d[1][i-1];

    for(int i=2;i<=n;i++){
        r[i][1] = d[i-1][1]+d[i][1];
        for(int j=2;j<=m;j++){
            r[i][j] = max(r[i][j-1],d[i-1][j])+d[i][j];
        }

        l[i][m] = d[i-1][m]+d[i][m];
        for(int j=m-1;j>=0;j--){
            l[i][j] = max(l[i][j+1],d[i-1][j])+d[i][j];
        }

        for(int j=1;j<=m;j++){
            d[i][j] = max(r[i][j],l[i][j]);
        }
    }
    cout<<d[n][m];
}