#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 10000000
int dist[1001];
vector<pair<int,int>>v[1001];
int N,M;
int excute_dijkstra(int start,int end)
{
     for(int i=1;i<=N;i++)
        dist[i]=INF;
    dist[start]=0;
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(int i=0;i<v[cur].size();i++)
        {
            int dest=v[cur][i].first;
            int cost=v[cur][i].second;
            if(dist[dest]>dist[cur]+cost)
                {
                    dist[dest]=dist[cur]+cost;
                    q.push(dest);
                }
        }
    }
    return dist[end];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y,c;
    cin>>N>>M;
   
    for(int i=0;i<M;i++)
    {
        cin>>x>>y>>c;
        v[x].push_back({y,c});
        v[y].push_back({x,c});
    }
    int v1,v2;
    cin>>v1>>v2;
    int x1=excute_dijkstra(1,v1);
    int y1=excute_dijkstra(1,v2);
    int x2=excute_dijkstra(v2,N);
    int y2=excute_dijkstra(v1,N);
    int bet=excute_dijkstra(v1,v2);
    
    long long ans1=x1+x2+bet;
    long long ans2=y1+y2+bet;
    if(ans1>ans2)
        ans1=ans2;
    if(ans1>=INF)
        ans1=-1;
    cout<<ans1;
}