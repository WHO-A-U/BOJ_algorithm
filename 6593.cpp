#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 0x3f3f3f3f
using namespace std;
bool d[31][31][31];
int dist[31][31][31];
int dx[]={0,0,0,0,1,-1};
int dy[]={1,-1,0,0,0,0};
int dz[]={0,0,1,-1,0,0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1){
    int f,r,c;
    cin>>f>>r>>c;
    if(f==0&&r==0&&c==0)
        return 0;
    char a;
    int sf,sr,sc;
    int ef,er,ec;
    for(int i=1;i<=f;i++)
    {
        for(int j=1;j<=r;j++)
        {
            for(int k=1;k<=c;k++)
            {
                dist[i][j][k]=INF;
                cin>>a;
                if(a=='.')
                    d[i][j][k]=true;
                else if(a=='S')
                    sf=i,sr=j,sc=k;
                else if(a=='E')
                        {
                         ef=i,er=j,ec=k;
                         d[i][j][k]=true;
                         }
                    else 
                        d[i][j][k]=false;
            }
        }
    }
    dist[sf][sr][sc]=0;
    queue<pair<int,pair<int,int>>>q;
    q.push({sf,{sr,sc}});
    while(!q.empty()){
        int cf=q.front().first;
        int cr=q.front().second.first;
        int cc=q.front().second.second;
        int tmp=dist[cf][cr][cc];
        q.pop();
        for(int i=0;i<6;i++)
        {
            int nf=cf+dx[i];
            int nr=cr+dy[i];
            int nc=cc+dz[i];
            if(1<=nf&&nf<=f&&1<=nr&&nr<=r&&1<=nc&&nc<=c)
            {
                if(d[nf][nr][nc]==true&&dist[nf][nr][nc]>dist[cf][cr][cc]+1)
                {
                    dist[nf][nr][nc]=dist[cf][cr][cc]+1;
                    q.push({nf,{nr,nc}});           
                }
            }
        }
    }
    if(dist[ef][er][ec]==INF)
        cout<<"Trapped!\n";
    else
        cout<<"Escaped in "<<dist[ef][er][ec]<<" minute(s).\n";
    }

    
}