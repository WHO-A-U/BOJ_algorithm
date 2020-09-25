#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int d[101][101];
bool v[101][101];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,x,cur=0;;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>x;
            d[i][j]=x;
            if(x==1)cur++;
        }
    }
    queue<pair<int,int> >q;
    int preCell;
    int time=0;
    while(cur>0){
        memset(v,false,sizeof(v));
        q.push(make_pair(0,0));
        v[0][0]=true;
        preCell=cur;
        time++;
        while(!q.empty()){
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = cr+dx[i];
                int nc = cc+dy[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m){
                    if(d[nr][nc]==1){
                        d[nr][nc]=2;
                    }else if(d[nr][nc]==0&&!v[nr][nc]){
                        q.push(make_pair(nr,nc));
                        v[nr][nc]=true;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(d[i][j]==2){
                    d[i][j]=0;
                    cur--;
                }
            }
        }
    }
    cout<<time<<"\n"<<preCell;
    
}