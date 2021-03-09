#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#define MAX 100'001
#define INF 0x3f3f3f3f
using namespace std;
int d[5][5][MAX];
int getCost(int cur ,int next){
    if(cur==0)return 2;
    if(cur==next)return 1;
    if(abs(cur-next)==2)return 4;
    return 3;    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=0;i<MAX;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                d[j][k][i]=INF;
            }
        }
    }

    d[0][0][0]=0;
    int n,idx=0;
    while(1){
        cin>>n;
        if(n==0)
            break;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(d[i][j][idx]==INF)
                    continue;
                int lc = getCost(i,n);
                int rc = getCost(j,n);                
                d[n][j][idx+1]=min(d[n][j][idx+1],d[i][j][idx]+lc);
                d[i][n][idx+1]=min(d[i][n][idx+1],d[i][j][idx]+rc);
            }
        }
        idx++;
    }
    
    int ans=INF;

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            ans = min(ans,d[i][j][idx]);
        }
    }
    cout<<ans;
}