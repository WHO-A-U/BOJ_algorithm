#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
bool d[1001][1001];
int val[1001][1001][2];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r,c;
    cin>>r>>c;
    string str;
    for(int i=0;i<r;i++)
    {
        cin>>str;
        for(int j=0;j<str.length();j++)
        {
            d[i][j]=(str[j]=='0'?false:true);
            val[i][j][0]=val[i][j][1]=0x3f3f3f;
        }
    }
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},1});
    val[0][0][0]=val[0][0][1]=1;
    while(!q.empty()){
        int cr=q.front().first.first;
        int cc=q.front().first.second;
        int chance=q.front().second;
        int dist=val[cr][cc][chance];
        q.pop();
        for(int i=0;i<4;i++){
            int nr=cr+dx[i];
            int nc=cc+dy[i];
            if(nr>=0&&nr<r&&nc>=0&&nc<c){
                if(d[nr][nc]==0)
                {
                    if(val[nr][nc][chance]>dist+1)
                    {
                        q.push({{nr,nc},chance});
                        val[nr][nc][chance]=dist+1;
                    }
                }
                else{
                    if(chance==1){
                        if(val[nr][nc][0]>dist+1)
                        {
                            q.push({{nr,nc},0});
                            val[nr][nc][0]=dist+1;
                        }
                    }
                }
            }
        }

    }
    if(val[r-1][c-1][0]==0x3f3f3f && val[r-1][c-1][1]==0x3f3f3f)
        cout<<"-1";
    else 
        cout<<min(val[r-1][c-1][0],val[r-1][c-1][1]);
}