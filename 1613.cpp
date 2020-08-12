#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int d[401][401];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        d[a][b]=-1;
        d[b][a]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(d[i][k]==1&&d[k][j]==1){
                    d[i][j]=1;
                    d[j][i]=-1;
                }
            }
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>a>>b;
        cout<<d[a][b]<<'\n';
    }
}