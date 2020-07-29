#include<iostream>
#include<queue>
#include<vector>
int INF=1000000000;
using namespace std;
vector<pair<int,int>>v[20001];
int dist[20001];
bool visit[20001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,start,a,b,c;
    cin>>n>>m>>start;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    for(int i=1;i<=n;i++)
        dist[i]=INF;
    dist[start]=0;
    priority_queue<pair<int,int>>q;
    q.push({0,start});
    while(!q.empty())
    {
        int cost=q.top().first;
        int cur=q.top().second;
        q.pop();
        if(visit[cur]==true)
            continue;
        visit[cur]=true;
        for(int i=0;i<v[cur].size();i++)
        {
            int des=v[cur][i].first;
            if(dist[des]>dist[cur]+v[cur][i].second){
                dist[des]=dist[cur]+v[cur][i].second;
                q.push({-dist[des],des});
            }
        }

    }
    for(int i=1;i<=n;i++)
    {
        if ( dist[i]== INF )
            cout<<"INF\n";
        else 
            cout<<dist[i]<<'\n';
    }
}