#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int d[101][101];
bool v[101][101];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int dist[7][7];
vector<pair<int,int>> isolate;
struct t{
  int r;
  int c;
  int dir;
  int leng;
  t(int r,int c,int dir,int leng):r(r),c(c),dir(dir),leng(leng){};
};
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<7;i++){
        for(int j=1;j<7;j++){
            dist[i][j]=INF;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>d[i][j];
        }
    }
    queue<pair<int,int>>q;
    int id=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(d[i][j]==0||v[i][j])
                continue;
            isolate.push_back({i,j});
            v[i][j]=true;
            q.push({i,j});
            d[i][j]=id;
            while(!q.empty()){
                int cr = q.front().first;
                int cc = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int nr = cr+dx[k];
                    int nc = cc+dy[k];
                    if(nr>=1&&nr<=n&&nc>=1&&nc<=m&&!v[nr][nc]&&d[nr][nc]!=0){
                        d[nr][nc]=id;
                        v[nr][nc]=true;
                        q.push({nr,nc});
                    }
                }
            }
            id++;
        }
    }
    // cout<<"******************************\n";
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<d[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    queue<struct t> que;
    for(int i=0;i<isolate.size();i++){
        int idx = d[isolate[i].first][isolate[i].second];
        memset(v,false,sizeof(v));
        que.push(t{
            isolate[i].first,
            isolate[i].second,
            0,
            0,
        });
        // printf("island %d : %d , %d \n",i,isolate[i].first,isolate[i].second);
        v[isolate[i].first][isolate[i].second]=true;
        while(!que.empty()){
            int cr = que.front().r;
            int cc = que.front().c;
            int cdir = que.front().dir;
            int len = que.front().leng;
            // printf("cr : %d cc : %d cdir : %d len :%d \n",cr,cc,cdir,len);
            que.pop();
            if(len>0){
                int nr = cr+dx[cdir];
                int nc = cc+dy[cdir];
                if(len>1){
                    if(nr>=1&&nr<=n&&nc>=1&&nc<=m){
                        if(d[nr][nc]!=idx&&d[nr][nc]!=0){
                            int newisland = d[nr][nc];
                            dist[idx][newisland]=min(dist[idx][newisland],len);
                            continue;
                        }
                        if(d[nr][nc]==0){
                            que.push({
                                nr,nc,cdir,len+1
                            });
                        }
                    }
                }else{
                    if(nr>=1&&nr<=n&&nc>=1&&nc<=m){
                        if(d[nr][nc]==0){
                            que.push({
                                nr,nc,cdir,len+1
                            });
                        }
                    }
                    continue;
                }
            }
            else{
                for(int j=0;j<4;j++){
                    int nr = cr+dx[j];
                    int nc = cc+dy[j];
                    if(nr<1||nr>n||nc<1||nc>m||v[nr][nc])
                        continue;
                    if(d[nr][nc]==0){
                        que.push({
                            nr,
                            nc,
                            j,
                            len+1,
                        });
                    }
                    else if(d[nr][nc]==idx&&!v[nr][nc]){
                        que.push({
                            nr,nc,j,len
                        });
                        v[nr][nc]=true;
                    }
                }

            }
        }
    }
    // cout<<endl;
    // for(int i=1;i<5;i++){
    //     printf("%d'th island ",i);
    //     for(int j=1;j<5;j++){
    //         printf("(%d : island) dist : %d ",j,dist[i][j]);
    //     }
    //     cout<<endl;
    // }

    vector<pair<int,pair<int,int>>> edge;
    int islandNum=isolate.size();
    int MST[10];
    for(int i=1;i<=10;i++)
        MST[i]=INF;
    bool vis[10];
    memset(vis,false,sizeof(vis));
    int start=1;
    vis[1]=true;
    int ans=0;
    for(int i=1;i<islandNum;i++){
        int idx=-1;
        int maxVal=INF;
        for(int j=1;j<=islandNum;j++){
            if(!vis[j]&&dist[start][j]<MST[j]){
                MST[j]=dist[start][j];
            }
        }
        for(int j=1;j<=islandNum;j++){
            if(!vis[j]&&MST[j]<maxVal){
                maxVal=MST[j];
                idx=j;
            }
        }
        if(idx==-1){
            cout<<"-1";
            return 0;
        }
        vis[idx]=true;
        start=idx;
        ans+=maxVal;
    }
    cout<<ans;
}