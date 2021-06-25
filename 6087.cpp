#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using vi = vector<int>;
using pii = pair<int,int>;
using vpii = vector<pii>;
char d[111][111];
int dist[111][111][4];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int w,h;
bool isValid(int r , int c){
    return r>=0&&r<h&&c>=0&&c<w;
}
vpii endPoint;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>w>>h;
    for(int i=0;i<h;i++){
        cin>>s;
        for(int j=0;j<w;j++){
            d[i][j] = s[j];
            if(s[j]=='C'){
                endPoint.push_back({i,j});  
            }
            for(int k=0;k<4;k++){
                dist[i][j][k]=INF;
            }
        }
    }

    queue<pair<pii,int>> q;
    pii start = endPoint.front();
    for(int i=0;i<4;i++){
        q.push({start,i});
        dist[start.first][start.second][i]=0;
    }

    while(!q.empty()){
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int curDir = q.front().second;
        int curDist = dist[cr][cc][curDir];
        q.pop();
        
        for(int i=0;i<4;i++){
            int nr = cr+dx[i];
            int nc = cc+dy[i];
            
            if(isValid(nr,nc) && d[nr][nc]!='*'){
                int extra=0;
                if(i!=curDir){
                    extra++;
                }
                if(dist[nr][nc][i]>curDist+extra){
                    dist[nr][nc][i]=curDist+extra;
                    q.push({{nr,nc},i});
                }
            }
        }

    }
    auto end = endPoint.back();
    int minVal = INF;
    for(int i=0;i<4;i++){
        minVal = min(minVal , dist[end.first][end.second][i]);
    }
    cout<<minVal;
}