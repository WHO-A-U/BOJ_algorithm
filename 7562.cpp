#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int dx[]={2,2,1,1,-1,-1,-2,-2};
int dy[]={1,-1,2,-2,2,-2,1,-1};
int d[301][301];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
            int n;
            cin>>n;
            memset(d,-1,sizeof(d));
            int sr,sc,er,ec;
            cin>>sr>>sc>>er>>ec;
            queue<pair<int,int> > q;
            q.push(make_pair(sr,sc));
            d[sr][sc]=0;
            while(!q.empty()){
                int cr = q.front().first;
                int cc = q.front().second;
                int cur = d[cr][cc];
                if(cr == er && cc == ec){
                    cout<<cur<<"\n";
                    break;
                }
                q.pop();
                for(int i=0;i<8;i++){
                    int nr = cr+dx[i];
                    int nc = cc+dy[i];
                    if(nr>=0&&nr<n&&nc>=0&&nc<n){
                        if(d[nr][nc]==-1||d[nr][nc]>cur+1){
                            d[nr][nc]=cur+1;
                            q.push(make_pair(nr,nc));
                        }
                    }
                }
            }

    }
}