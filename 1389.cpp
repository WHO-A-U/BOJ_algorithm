#include<iostream>
#include<vector>
#include<algorithm>
#define INF 987654321
using namespace std;
int dist[101][101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,a,b,c;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                dist[i][j]=0;
            else
                dist[i][j]=INF;
        }
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        dist[a][b]=dist[b][a]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
    int sum[101];
    int minsum=INF;
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        for(int j=1;j<=n;j++)
        {
            if(dist[i][j]!=INF)
            {
                ans+=dist[i][j];
            }
        }
        minsum=min(ans,minsum);
        sum[i]=ans;
    }
    vector<int> arc;
    for(int i=1;i<=n;i++)
    {
        if(sum[i]==minsum)
        { 
            cout<<i;
            return 0;
        }
    }

}