#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define INF 987654321
int dist[101][101];
int v[101][101];
int main()
{
    memset(dist,INF,sizeof(dist));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,a,b,c;
    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
            dist[i][j]=(i==j?0:INF);
    }
    for(int i=0;i<M;i++)
    {
        cin>>a>>b>>c;
        if(dist[a][b]>c)
        {
            dist[a][b]=c;
            v[a][b]=b;
        }
    }
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
              {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    v[i][j]=v[i][k];
                }
            }
        }
    }
    
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(i==j||dist[i][j]==INF)
                cout<<"0 ";
            else 
                cout<<dist[i][j]<<" ";
        }
        cout<<'\n';
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(i==j||dist[i][j]==INF){
                cout<<"0\n";
                continue;
            }
            vector<int> p(1,i);
            for(int k=i;k!=j;){
                p.push_back(k=v[k][j]);
            }
            cout<<p.size();
            for(int k : p) cout<<" "<<k;
            cout<<"\n";
        }
    }
    return 0;
}