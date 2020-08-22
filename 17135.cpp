#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int m[16][16];
vector<int> tmp;
int r,c,dist,ans=0;
int dx[]={0,-1,0};
int dy[]={-1,0,1};
int d[16][16];
bool isEndGame(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(d[i][j]==1)
                return false;
        }
    }
    return true;
}
void excute(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            d[i][j]=m[i][j];
        }
    }
    int cnt=0;
    queue<pair<int,int>> q;
    while(!isEndGame()){
        vector<pair<int,int>> target;
        for(int i=0;i<tmp.size();i++){
            bool v[16][16];
            memset(v,false,sizeof(v));
            q.push({r,tmp[i]});
            bool flag=false;
            while(!q.empty()&&!flag){
                // cout<<'#';
                int cr = q.front().first;
                int cc = q.front().second;
                q.pop();
                for(int j=0;!flag&&j<3;j++){
                    int nr = cr+ dx[j];
                    int nc = cc+ dy[j];
                    if(nr>=0&&nr<r&&nc>=0&&nc<c){
                        if(abs(r-nr)+abs(tmp[i]-nc)<=dist&&!v[nr][nc]){
                            if(d[nr][nc]==1){
                                target.push_back({nr,nc});
                                flag=true;
                            }else{
                                q.push({nr,nc});
                            }
                            v[nr][nc]=true;
                        }
                    }
                }
            }
            while(!q.empty())
                q.pop();
        }
        for(int i=0;i<target.size();i++){
            int row = target[i].first;
            int col = target[i].second;
            if(d[row][col]==1){
                cnt++;
                d[row][col]=0;
            }
        }
        for(int i=r-1;i>0;i--){
            for(int j=0;j<c;j++){
                d[i][j]=d[i-1][j];
            }
        }
        for(int i=0;i<c;i++){
            d[0][i]=0;
        }
    }
    ans=max(ans,cnt);
}
void go(int cnt){
    if(tmp.size()==3){
        excute();
        return ;
    }
    if(cnt<0){
        return ;
    }
    tmp.push_back(cnt);
    go(cnt-1);
    tmp.pop_back();
    go(cnt-1);
    
}
int main(){
    cin>>r>>c>>dist;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>m[i][j];
        }
    }
    go(c-1);
    cout<<ans;
}