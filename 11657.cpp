#include<iostream>
#include<vector>
using namespace std;
#define INF 987654321
long long dist[501];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int,pair<int,int>>>v;
    int N,M,a,b,c;
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        dist[i]=INF;
    dist[1]=0;
    for(int i=0;i<M;i++)
    {
        cin>>a>>b>>c;
        v.push_back({c,{a,b}});
    }
    bool ncycle=false;
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int x=v[j].second.first;
            int y=v[j].second.second;
            int cost=v[j].first;
            if(dist[x]!=INF && dist[y]>dist[x]+cost){
                dist[y]=dist[x]+cost;
                if(i==N){
                    ncycle=true;
                }
            }
        }
    }
    if(ncycle)
        cout<<"-1";
    else
    {
        for(int i=2;i<=N;i++)
        {
            if(dist[i]!=INF)
                cout<<dist[i]<<'\n';
            else 
                cout<<"-1\n";
        }
    }
}