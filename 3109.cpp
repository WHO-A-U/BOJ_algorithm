#include <bits/stdc++.h>
using namespace std;
int n,m,ans=0;
bool v[10001][501];
int d[10001][501];
int dx[]={-1,0,1};
bool flag=false;
bool isValid(int r , int c){
    return r>=0&&r<n&&c>=0&&c<m;
}
void go(int r , int c){
    if(c==m-1){
        if(v[r][c]){
            flag=true;
            ans++;
        }
        return ;
    }
    v[r][c]=false;

    for(int k=0;k<3;k++){
        int nr = r+dx[k];
        if(isValid(nr,c+1)&&v[nr][c+1])
            go(nr,c+1);
        if(flag)
            break;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    memset(v,false,sizeof(v));
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='.')
                v[i][j]=true;
        }
    }  

    for(int i=0;i<n;i++){
        flag=false;
        go(i,0);
    }
    
    cout<<ans;
}
