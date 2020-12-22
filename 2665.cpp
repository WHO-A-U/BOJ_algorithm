#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
char c[51][51];
int d[51][51];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n;
string s;
queue<pair<int,int>> q;
void calPath(){
    q.push({0,0});
    d[0][0]=0;
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        int cd = d[cr][cc];
        q.pop();
        for(int i=0;i<4;i++){
            int nr = cr + dx[i];
            int nc = cc + dy[i];
            int z=cd;
            if(nr>=0&&nr<n&&nc>=0&&nc<n){
                if(c[nr][nc]=='0')
                    z++;
                if(d[nr][nc]==-1||d[nr][nc]>z){
                    d[nr][nc]=z;
                    q.push({nr,nc});
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(d,-1,sizeof(d));
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<n;j++){
            c[i][j]=s[j];
        }
    }
    calPath();
    cout<<d[n-1][n-1];
}