#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int d[101][101];
bool v1[101][101];
bool v2[101][101];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int ans1=0,ans2=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    char a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           cin>>a;
           if(a=='R')d[i][j]=1;
           if(a=='G')d[i][j]=2;
           if(a=='B')d[i][j]=3;
        }
    }
    queue<pair<int,int>>q1;
    queue<pair<int,int>>q2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v1[i][j]==false){
                q1.push({i,j});
                v1[i][j]=true;
                ans1++;
            }
            if(v2[i][j]==false){
                q2.push({i,j});
                v2[i][j]=true;
                ans2++;
            }
            while(!q1.empty()){
                int cx=q1.front().first;
                int cy=q1.front().second;
                q1.pop();
                for(int k=0;k<4;k++)
                {
                    int nx = cx+dx[k];
                    int ny = cy+dy[k];
                    if(nx>=0&&nx<n && ny>=0&&ny<n&&v1[nx][ny]==false){
                        if(d[cx][cy]==d[nx][ny]){
                        v1[nx][ny]=true;
                        q1.push({nx,ny});
                        }
                    }
                }
            }
            while(!q2.empty()){
                int cx=q2.front().first;
                int cy=q2.front().second;
                q2.pop();
                for(int k=0;k<4;k++)
                {
                    int nx = cx+dx[k];
                    int ny = cy+dy[k];
                    if(nx>=0&&nx<n && ny>=0&&ny<n&&v2[nx][ny]==false){
                        if((d[cx][cy]==1 ||d[cx][cy]==2)&&(d[nx][ny]==1||d[nx][ny]==2))
                        {
                                v2[nx][ny]=true;
                                q2.push({nx,ny});   
                        }
                        if(d[cx][cy]==d[nx][ny] && d[cx][cy]==3){
                            v2[nx][ny]=true;
                            q2.push({nx,ny});
                        }
                    }
                }
            }
        }
    }
    cout<<ans1<<" "<<ans2;

}