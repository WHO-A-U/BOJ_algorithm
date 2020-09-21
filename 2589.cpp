#include <iostream>
#include <algorithm>
#include <cstring>
#include<string>
#include<queue>
using namespace std;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
char d[51][51];
int v[51][51];
int n,m;
queue<pair< int , int > > q;
int findLongPath(int row,int col){
    if(d[row][col]=='W')
        return 0;
    memset(v,-1,sizeof(v));
    v[row][col]=0;
    q.push(make_pair(row,col));
    int cnt=0;
    while(!q.empty()){
        int cr=q.front().first;
        int cc=q.front().second;
        int cur=v[cr][cc];
        cnt=max(cnt,cur);
        q.pop();
        for(int i=0;i<4;i++){
            int nr = cr+dx[i];
            int nc = cc+dy[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m){
                if(d[nr][nc]=='L'){
                    if(v[nr][nc]==-1||(v[nr][nc]>0&&(v[nr][nc]>cur+1))){
                        v[nr][nc]=cur+1;
                        q.push( make_pair( nr , nc ) );
                    }
                }
            }
        }
    }
    return cnt;
}
int main() {
    string str;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>str;
        for(int j=0;j<m;j++){
            d[i][j]=str[j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans=max(ans,findLongPath(i,j));
        }
    }
    cout<<ans;
}
