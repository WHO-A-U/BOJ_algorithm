#include<iostream>
#include<algorithm>
#define INF 1000000
using namespace std;
int dist[401][401];
int main()
{
    int v,e,a,b,c;
    cin>>v>>e;
    for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
            {
                if(i==j)
                    dist[i][j]=0;
                else 
                    dist[i][j]=INF;
            }
    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>c;
        if(dist[a][b]==0)
            dist[a][b]=c;
        else 
            if(dist[a][b]>c)
                dist[a][b]=c;
    }
    for(int k=1;k<=v;k++)
        for(int i=1;i<=v;i++)
            for(int j=1;j<=v;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
    int ans=INF;
    for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
        {
            if(i==j)
                continue;
            else{
                if(dist[i][j]+dist[j][i]<ans)
                    ans=dist[i][j]+dist[j][i];
            }
        }
    if(ans==INF)
        cout<<"-1";
    else 
        cout<<ans;
}