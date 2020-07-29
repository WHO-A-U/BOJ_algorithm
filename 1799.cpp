#include<iostream>
#include<algorithm>
using namespace std;
int d[11][11];
int ans[2];
int n;
int dx[]={1,1,-1,-1};
int dy[]={1,-1,-1,1};
void go0(int number,int cnt,int d[][11]){
    if(number==(n*n-2)){
        if(d[n-1][n-2]==1)
            ans[0]=max(ans[0],cnt+1);
        else
            ans[0]=max(ans[0],cnt);
        return ;
    }
    int r = number/n;
    int c = number%n;
    if((r+c)%2==0){
        go0(number+1,cnt,d);
        return ;
    }
    if(d[r][c]==1){
        int New[11][11];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                New[i][j]=d[i][j];
            }
        }
        New[r][c]=0;
        for(int i=0;i<4;i++){
            int nr = r+dx[i];
            int nc = c+dy[i];
            while(nr>=0&&nr<n&&nc>=0&&nc<n){
                New[nr][nc]=0;
                nr+=dx[i];
                nc+=dy[i];
            }
        }
        go0(number+1,cnt+1,New);

    }
    go0(number+1,cnt,d);
    return ;
}
void go1(int number,int cnt,int d[][11]){
    if(number==(n*n-1)){
        if(d[n-1][n-1]==1)
            ans[1]=max(ans[1],cnt+1);
        else
            ans[1]=max(ans[1],cnt);
        return ;
    }
    int r = number/n;
    int c = number%n;
    if((r+c)%2==1){
        go1(number+1,cnt,d);
        return ;
    }
    if(d[r][c]==1){
        int New[11][11];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                New[i][j]=d[i][j];
            }
        }
        New[r][c]=0;
        for(int i=0;i<4;i++){
            int nr = r+dx[i];
            int nc = c+dy[i];
            while(nr>=0&&nr<n&&nc>=0&&nc<n){
                New[nr][nc]=0;
                nr+=dx[i];
                nc+=dy[i];
            }
        }
        go1(number+1,cnt+1,New);

    }
    go1(number+1,cnt,d);
    return ;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];   
        }
    }
    if(n==1){
        cout<<d[0][0];
        return 0;
    }
    go0(0,0,d); 
    go1(0,0,d);
    cout<<ans[0]+ans[1];
}
