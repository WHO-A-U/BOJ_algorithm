#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
int d[51][51];
vector<pair<int,int>> virus;
vector<int> tmp;
int ans=0x3f3f3f3f;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void bfs(){
    int dd[51][51];
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(d[i][j]==2){
                dd[i][j]=3;
            }
            if(d[i][j]==0){
                cnt++;
                dd[i][j]=0;
            }
            if(d[i][j]==1)
                dd[i][j]=1;
        }
    }
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<tmp.size();i++){
        int num=tmp[i];
        int r=virus[num].first;
        int c=virus[num].second;
        dd[r][c]=2;
        q.push({{r,c},0});
    }
    int maxtime=0;
    while(!q.empty()){
        int cr=q.front().first.first;
        int cc=q.front().first.second;
        int ctime=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nr = cr+dx[i];
            int nc = cc+dy[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<n){
                if(dd[nr][nc]==0||dd[nr][nc]==3){
                    if(dd[nr][nc]==0){

                        cnt--;
                        maxtime=max(maxtime,ctime+1);
                    }
                    dd[nr][nc]=2;
                    q.push({{nr,nc},ctime+1});
                }
            }
        }
    }
    if(cnt==0){
        ans=min(ans,maxtime);
    }
    return ;
}
void go(int stage){
    if(tmp.size()==m){
        //bfs go!!!
        // cout<<"bfs go!\n";
        bfs();
        return ;
    }
    if(stage==virus.size())
        return ;
    tmp.push_back(stage);
    go(stage+1);
    tmp.pop_back();
    go(stage+1);
    return ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];
            if(d[i][j]==2){
                virus.push_back({i,j});
            }
        }
    }
    go(0);
    if(ans==0x3f3f3f3f)
        cout<<-1;
    else
        cout<<ans;
}