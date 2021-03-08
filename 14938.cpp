#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define INF 0x3f3f3f3f
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,r,a,b,c;
    cin>>n>>m>>r;
    vvi d(n,vi(n,INF));
    vi item(n);
    for(int i=0;i<n;i++){
        cin>>item[i];
        d[i][i]=0;
    }
    for(int i=0;i<r;i++){
        cin>>a>>b>>c;
        a--;
        b--;
        d[a][b]=d[b][a]=c;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][k]+d[k][j]<d[i][j]){
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }

    int cnt=0,maxCnt=0;
    for(int i=0;i<n;i++){
        cnt=0;
        for(int j=0;j<n;j++){
            if(d[i][j]<=m){
                cnt+=item[j];
            }
        }
        maxCnt = max(cnt , maxCnt);
    }
    cout<<maxCnt;

}