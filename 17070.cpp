#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
bool d[21][21];
int dx[]={0,1,1};
int dy[]={1,1,0};
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];
        }
    }
    vector<int> dir[3];
    dir[0].push_back(0);
    dir[0].push_back(1);
    dir[1].push_back(0);
    dir[1].push_back(1);
    dir[1].push_back(2);
    dir[2].push_back(1);
    dir[2].push_back(2);
    //0 right
    //1 diagoal
    //2 down
    int ans=0;
    queue<pair<pair<int,int>,int>> q; // nr nc dir;
    q.push({{0,1},0});
    while(!q.empty()){
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int cd = q.front().second;
        q.pop();
        if(cr==n-1&&cc==n-1){
            ans++;
            continue;
        }
        for(int i=0;i<dir[cd].size();i++){
            int nr = cr + dx[dir[cd][i]];
            int nc = cc + dy[dir[cd][i]];
            if(dir[cd][i]==1){
                if(nr<n&&nc<n&&!d[nr][nc]&&!d[nr-1][nc]&&!d[nr][nc-1]){
                    q.push({{nr,nc},dir[cd][i]});
                }
            }
            else{
                if(nr<n&&nc<n&&!d[nr][nc]){
                        q.push({{nr,nc},dir[cd][i]});
                    }
            }
        }
    }
    cout<<ans;
    
}