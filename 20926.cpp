#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#define INF 0x3f3f3f3f
using namespace std;
char map[501][501];
int d[501][501];
int w,h,ans;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
pair<pair<int,int>,int> go(int r,int c,int dir){
    int nr = r+dx[dir];
    int nc = c+dy[dir];
    int sum=0;
    while(true){
        if(nr>=0&&nr<h&&nc>=0&&nc<h){
            if(map[nr][nc]=='H'){
                sum=-1;
                break;
            }
            if(map[nr][nc]=='E'){
                break;
            }
            if(map[nr][nc]=='R'){
                nr-=dx[dir];
                nc-=dy[dir];
                break;
            }
            else{
                sum+=(map[nr][nc]-'0');
            }
            nr = nr+dx[dir];
            nc = nc+dy[dir];
        }
        else{
            sum=-1;
            break;
        }
    }
    pair<int,int> a = make_pair(nr,nc);
    return make_pair(a,sum);
}
int main(){
    cin>>w>>h;
    string s;
    int sr,sc,dr,dc;
    ans=INF;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            d[i][j]=INF;
        }
    }
    for(int i=0;i<h;i++){
        cin>>s;
        for(int j=0;j<w;j++){
            map[i][j]=s[j];
            if(s[j]=='T'){
                sr = i;
                sc = j;
                map[i][j]='0';
            }
            if(s[j]=='E'){
                dr = i;
                dc = j;
            }
        }
    }
    queue<pair<int,int> > q;
    q.push(make_pair(sr,sc));
    d[sr][sc]=0;
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        int dist = d[cr][cc];
        q.pop();
        for(int i=0;i<4;i++){
            pair<pair<int,int>,int> next = go(cr,cc,i);
            int cost = next.second;
            if(cost >= 0){
                int nr = next.first.first;
                int nc = next.first.second;
                if(d[nr][nc]>dist+cost){
                    d[nr][nc]=dist+cost;
                    if(map[nr][nc]!='E'){
                        q.push(make_pair(nr,nc));
                    }
                }
            }
        }
    }
    if(d[dr][dc]==INF){
        ans=-1;
    }
    else{
        ans=d[dr][dc];
    }
    cout<<ans;
    
}