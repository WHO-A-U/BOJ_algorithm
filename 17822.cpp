#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int d[51][51];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m,t;
void roll(int row,int dir){
    if(dir==0){
        int tmp = d[row][m];
        for(int i=m;i>1;i--){
            d[row][i]=d[row][i-1];
        }
        d[row][1]=tmp;
    }
    else{
        int tmp = d[row][1];;
        for(int i=1;i<m;i++){
            d[row][i]=d[row][i+1];
        }
        d[row][m]=tmp;
    }
}
void rotate(int num,int dir,int cnt){
    for(int i=num;i<=n;i=i+num){
        for(int j=0;j<cnt;j++){
            roll(i,dir);
        }
    }
}
void findJoint(){
    bool v[51][51];
    memset(v,false,sizeof(v));
    queue<pair<int,int>> q;
    int univFlag=false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!v[i][j]&&d[i][j]!=0){
                int flag =false;
                v[i][j]=true;
                q.push({i,j});
                int curnum = d[i][j];
                while(!q.empty()){
                    int cr = q.front().first;
                    int cc = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nr = cr+dx[k];
                        int nc = cc+dy[k];
                        if(nr>n)continue;
                        if(nr<1)continue;
                        if(nc>m)nc=1;
                        if(nc<1)nc=m;
                        if(!v[nr][nc]&&d[nr][nc]==curnum){
                            flag=true;
                            v[nr][nc]=true;
                            q.push({nr,nc});
                            d[nr][nc]=0;
                        }
                    }
                }
                if(flag){
                    d[i][j]=0;
                    univFlag=true;
                }
            }
        }
    }
    int total=0,cnt=0;
    if(!univFlag){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(d[i][j]!=0){
                    total+=d[i][j];
                    cnt++;
                }
            }
        }
        if(cnt==0)
            return ;
        int div = total/cnt,mod = total%cnt;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(d[i][j]!=0){
                    if(d[i][j]>div)
                        d[i][j]--;
                    else if(d[i][j]<div||d[i][j]==div&&mod>0)
                        d[i][j]++;
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>d[i][j];
        }
    }
    for(int i=0;i<t;i++){
        int x,d,k;
        cin>>x>>d>>k;
        rotate(x,d,k);
        findJoint();
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans+=d[i][j];
        }
    }
    cout<<ans;
}