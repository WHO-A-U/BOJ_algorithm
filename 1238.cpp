#include<iostream>
#include<vector>
#include<algorithm>
int d[1001][1001];
#define INF 987654321
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int n,m,x,a,b,c;
   cin>>n>>m>>x;
   for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        if(i==j)
            d[i][j]=0;
        else 
            d[i][j]=INF;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        d[a][b]=c;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                {
                    if(d[i][j]>d[i][k]+d[k][j])
                        d[i][j]=d[i][k]+d[k][j];
                }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,d[i][x]+d[x][i]);
    }
    cout<<ans;
    
}