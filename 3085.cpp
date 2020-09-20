#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
char d[51][51];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n;
int searchRow(int r1,int r2){
    int ans=1,cnt=0;
    for(int i=1;i<n;i++){
        if(d[r1][i]==d[r1][i-1]){
            if(cnt==0)
                cnt=2;
            else
                cnt++;
            ans=max(ans,cnt);
        }else{
            cnt=0;
        }
    }
    cnt=0;
    for(int i=1;i<n;i++){
        if(d[r2][i]==d[r2][i-1]){
            if(cnt==0)
                cnt=2;
            else
                cnt++;
            ans=max(ans,cnt);
        }else{
            cnt=0;
        }
    }
    return ans;
}
int searchCol(int c1,int c2){
    int ans=1,cnt=0;
    for(int i=1;i<n;i++){
        if(d[i][c1]==d[i-1][c1]){
            if(cnt==0)
                cnt=2;
            else
                cnt++;
            ans=max(ans,cnt);
        }else{
            cnt=0;
        }
    }
    cnt=0;
    for(int i=1;i<n;i++){
        if(d[i][c2]==d[i-1][c2]){
            if(cnt==0)
                cnt=2;
            else
                cnt++;
            ans=max(ans,cnt);
        }else{
            cnt=0;
        }
    }
    return ans;
}
void swapD(char &a,char &b){
    char tmp = a;
    a=b;
    b=tmp;
    return ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<n;j++){
            d[i][j]=s[j];
        }
    }
    int ans=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<4;k++){
                int nr = i+dx[k];
                int nc = j+dy[k];
                if(nr>=0&&nr<n&&nc>=0&&nc<n){
                    // if(d[i][j]!=d[nr][nc]){
                        swapD(d[i][j],d[nr][nc]);
                        if(k<2){
                            ans=max(ans,searchRow(i,nr));
                        }else{
                            ans=max(ans,searchCol(j,nc));
                        }
                        swapD(d[i][j],d[nr][nc]);
                        if(k<2){
                            ans=max(ans,searchRow(i,nr));
                        }else{
                            ans=max(ans,searchCol(j,nc));
                        }
                    // }
                }
            }
        }
    }
    cout<<ans;
}