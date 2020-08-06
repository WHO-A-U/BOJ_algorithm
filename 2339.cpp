#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int d[21][21];
int row[21],col[21];
int dp[21][21][21][21][2];//0 -> 불순물 1 -> 보석
int n;
int dnc(int rlo,int rhi ,int clo ,int chi,bool mode){
    // printf("go! from %d %d ->to %d %d  \n",rlo,rhi,clo,chi);
    
    if(dp[rlo][rhi][clo][chi][0]==-1){
        int cnt=0;
        int dirty=0;
        for(int i=rlo;i<=rhi;i++){
            for(int j=clo;j<=chi;j++){
                if(d[i][j]==1){
                    dirty++;
                }
                if(d[i][j]==2)
                    cnt++;
                }
            }

        dp[rlo][rhi][clo][chi][0]=dirty;
        dp[rlo][rhi][clo][chi][1]=cnt;
    }
    if(dp[rlo][rhi][clo][chi][1]==0||(dp[rlo][rhi][clo][chi][1]>1&&dp[rlo][rhi][clo][chi][0]==0))
        return 0;
    if(dp[rlo][rhi][clo][chi][1]==1&&dp[rlo][rhi][clo][chi][0]>0)
        return 0;
    if(dp[rlo][rhi][clo][chi][1]==1&&dp[rlo][rhi][clo][chi][0]==0)
        return 1;
    int ans=0;
    if(mode){
        for(int i=rlo+1;i<rhi;i++){
            bool flag=false;
            for(int j=clo;j<=chi;j++){
                if(d[i][j]==1){
                    flag=true;
                }
                else if(d[i][j]==2){
                    flag=false;
                    break;
                }
            }
            if(flag){
                int down=dnc(rlo,i-1,clo,chi,!mode);
                int up=dnc(i+1,rhi,clo,chi,!mode);
                // if(down!=-1&&up!=-1){
                    // printf("row! from %d %d ->to %d %d : %d\n",rlo,rhi,clo,chi,up*down);
                    ans+=(down*up);
                // }
            }
        }
    }
    else{
        for(int i=clo+1;i<chi;i++){
            bool flag=false;
            for(int j=rlo;j<=rhi;j++){
                if(d[j][i]==1){
                    flag=true;
                }
                else if(d[j][i]==2){
                    flag=false;
                    break;
                }
            }
            if(flag){
                int left=dnc(rlo,rhi,clo,i-1,!mode);
                int right=dnc(rlo,rhi,i+1,chi,!mode);
                // if(left!=-1&&right!=-1){
                    // printf("col! from %d %d ->to %d %d : %d\n",rlo,rhi,clo,chi,left*right);
                    ans+=(left*right);
                // }
            }
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];
            if(d[i][j]==1){
                row[i]++;
                col[j]++;
            }
        }
    }
    memset(dp,-1,sizeof(dp));
    int ans=dnc(0,n-1,0,n-1,true)+dnc(0,n-1,0,n-1,false);
    cout<<(ans>0?ans:-1);
}
