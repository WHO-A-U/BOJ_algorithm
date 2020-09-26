#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int d[101][101];
queue<pair<int,int>> q;
queue<pair<int,int>> ch;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool v[101][101];
bool ches[10001];
int n,m;
void airClean(){
    memset(v,false,sizeof(v));
    q.push({0,0});
    v[0][0]=true;
    d[0][0]=0;
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nr = cr+dx[i];
            int nc = cc+dy[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&!v[nr][nc]){
                if(d[nr][nc]==-1){
                    d[nr][nc]=0;
                    q.push({nr,nc});
                    v[nr][nc]=true;
                }else if(d[nr][nc]>=0){
                    q.push({nr,nc});
                    v[nr][nc]=true;
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>d[i][j];
            if(d[i][j]==1){
                cnt++;
                d[i][j]=-2;
                ch.push({i,j});
            }else{
                d[i][j]=-1;
            }
        }
    }
    q.push({0,0});
    int ans=0;
    while(cnt>0){
        airClean();
		queue<pair<int,int>> tmpch;
        while(!ch.empty()){
            
			int cr = ch.front().first;
			int cc = ch.front().second;
			int tmp=0;
			ch.pop();
			for(int j=0;j<4;j++){
				int nr = cr+dx[j];
				int nc = cc+dy[j];
				if(d[nr][nc]>=0&&d[nr][nc]<=ans){
					tmp++;
				}
			}
			if(tmp>=2){
				d[cr][cc]=ans+1;
				cnt--;
			}else{
				tmpch.push({cr,cc});
			}
            
        }
		ch=tmpch;
        ans++;
    }
    cout<<ans;
}