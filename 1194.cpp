#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
char d[51][51];
int v[51][51][1<<6];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,sr,sc;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        for(int j=0;j<m;j++){
            d[i][j]=str[j];
            if(d[i][j]=='0'){
                sr=i;
                sc=j;
            }
        }
    }
    memset(v,-1,sizeof(v));
    queue<pair<pair<int,int>,int>> q;
    v[sr][sc][0]=0;
    q.push({{sr,sc},0});
    while(!q.empty()){
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int key = q.front().second;
        int cost = v[cr][cc][key];
        if(d[cr][cc]=='1'){
            cout<<cost;
            return 0;
        }
        q.pop();
        if(d[cr][cc]>='a'&&d[cr][cc]<='f'){
            // cout<<"!!";
            key=key|(1<<(d[cr][cc]-'a'));
            v[cr][cc][key]=cost;
        }
        // printf("cr : %d cc : %d key : %d cost : %d \n",cr,cc,key,cost);
        for(int i=0;i<4;i++){
            int nr = cr+dx[i];
            int nc = cc+dy[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&d[nr][nc]!='#'){
                if(d[nr][nc]>='A'&&d[nr][nc]<='F'){
                    if(key&(1<<(d[nr][nc]-'A')))
                    {
                        if(v[nr][nc][key]==-1||v[nr][nc][key]>v[cr][cc][key]+1){
                            v[nr][nc][key]=cost+1;
                            q.push({{nr,nc},key});
                        }
                    }
                }
                else if(v[nr][nc][key]==-1||v[nr][nc][key]>v[cr][cc][key]+1){
                    v[nr][nc][key]=cost+1;
                    q.push({{nr,nc},key});
                }
            }
        }
    }
    cout<<-1;
    return 0;
    
}
