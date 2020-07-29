#include<iostream>
#include<vector>
using namespace std;
long long d[101][10][1<<10];
int dx[]={1,-1};
int main(){
    int n,m=1000000000;
    cin>>n;
    for(int i=1;i<=9;i++)
        d[1][i][1<<i]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<=(1<<10)-1;k++){
                for(int x=0;x<2;x++){
                    int pre = j+dx[x];
                    if(pre>=0&&pre<=9){
                        if(d[i-1][pre][k]>0){
                            d[i][j][k|(1<<j)]+=(d[i-1][pre][k]%m);
                        }
                    }
                }
            }
        }
    }
    long long ans=0;
    for(int i=0;i<10;i++){
        ans+=d[n][i][(1<<10)-1];
    }
    cout<<ans%m;
}