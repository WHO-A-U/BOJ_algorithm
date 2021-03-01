#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
using pii = pair<int ,int>;
int d[1002][201];  // t ,v    t시간에 v지점에서 최대 점수
vector<int> e[201];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t,a,b;
    cin>>n>>t;

    for(int i=0;i<=t;i++){
        for(int j=0;j<n;j++){
            d[i][j]=-1;
        }
    }

    vector<int> entry(n,0);
    vector<int> exp(n,0);

    for(int i=0;i<n;i++){
        cin>>entry[i]>>exp[i];
        if(entry[i]==0){
            d[0][i]=0;

        }
    }

    for(int i=0;i<n;i++){
        e[i].assign(n,0);
        for(int j=0;j<n;j++){
            cin>>e[i][j];
        }
    }

    for(int i=1;i<=t;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(j==k){
                    if(d[i-1][j]>=0){
                        d[i][j]=max(d[i][j],d[i-1][j]+exp[j]);
                    }
                }else{
                    if(i-e[j][k]>=0&&d[i-e[j][k]][k]>=entry[j]){
                        d[i][j]=max(d[i][j],d[i-e[j][k]][k]);
                    }
                }
            }
        }
    }
    
    int ans=0;
    for(int i=0;i<n;i++){
        ans = max(ans , d[t][i]);
    }
    
    cout<<ans;
    return 0;
}