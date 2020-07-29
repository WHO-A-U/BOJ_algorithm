#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int D[101][101][101];
int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};
queue<pair<pair<int,int>,pair<int,int>>> q;//row,col /height,day
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,h,x;
    cin>>m>>n>>h;
    int unready=0;
    for(int i=0;i<h;i++){
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
               cin>>x;
               D[row][col][i]=x; 
               if(x==1){
                   q.push({{row,col},{i,0}});
               }
               if(x==0){
                   unready++;
               }
            }
        }
    }
    if(unready==0){
        cout<<0;
        return 0;
    }//1 익은거 0 익지 않은거 -1 없는거 
    while(!q.empty()){
        int cr=q.front().first.first;
        int cc=q.front().first.second;
        int ch=q.front().second.first;
        int cd=q.front().second.second;
        q.pop();
        for(int i=0;i<6;i++)
        {
            int nr=cr+dx[i];
            int nc=cc+dy[i];
            int nh=ch+dz[i];
            int nd=cd+1;
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&nh>=0&&nh<h){
                if(D[nr][nc][nh]==0){
                    D[nr][nc][nh]=1;
                    unready--;
                    q.push({{nr,nc},{nh,nd}});
                }
            }
            if(unready==0)
            {
                cout<<nd;
                return 0;
            }
        }
    }
    if(unready!=0)
        cout<<-1;
    
}