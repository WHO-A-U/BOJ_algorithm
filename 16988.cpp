#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
int original[21][21];
int duplicated[21][21];
int visit[21][21];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
vector<pair<int,int>> Cases;
vector<pair<int,int>> Selected;
vector<int> setNum;
int ans=0;
void resetVisit(){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            visit[i][j]=0;
        }
    }
}
void bfs(){
    resetVisit();
    queue<pair<int,int>> q;
    int cnt=1;
    bool iscomplet;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(duplicated[i][j]==2&&visit[i][j]==0){
                iscomplet =true;
                q.push({i,j});
                while(!q.empty()){
                    int r=q.front().first;
                    int c=q.front().second;
                    if(visit[r][c]!=0)
                    {
                        q.pop();
                        continue;
                    }
                    visit[r][c]=cnt;
                    q.pop();
                    for(int k=0;k<4;k++)
                    {
                        int nr=r+dx[k];
                        int nc=c+dy[k];
                        if(nr>=1&&nr<=n&&nc>=1&&nc<=m){
                            if(duplicated[nr][nc]==0){
                                iscomplet=false;
                            }
                            else{
                                if(duplicated[nr][nc]==2&&visit[nr][nc]==0){
                                    q.push({nr,nc});
                                }
                            }
                        }
                    }
                }
                if(iscomplet==true){
                    setNum.push_back(cnt);
                }
                cnt++;
            }
        }
    }
    if(setNum.size()>0){
        int temp=0;
        for(int i=0;i<setNum.size();i++)
        {
            int x=setNum[i];
            for(int z=1;z<=n;z++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(visit[z][j]==x){
                        temp++;
                    }
                }
            }
        }
        setNum.clear();
        ans=max(ans,temp);
    }
}
void makeTable(){
    for(int i=0;i<Selected.size();i++)
        duplicated[Selected[i].first][Selected[i].second]=1;
    bfs();
    for(int i=0;i<Selected.size();i++)
        duplicated[Selected[i].first][Selected[i].second]=0;
}
void select(int index){
    if(Selected.size()==2){
        makeTable();
        return ;
    }
    if(index>=Cases.size()){
        return ;
    }
    Selected.push_back(Cases[index]);
    select(index+1);
    Selected.pop_back();
    select(index+1);
    return ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin>>n>>m;//row column
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>x;
            original[i][j]=x;
            if(x==0){
                Cases.push_back({i,j});//row,column
            }
        }
    }    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            duplicated[i][j]=original[i][j];
        }
    }
    select(0);
    cout<<ans;
}