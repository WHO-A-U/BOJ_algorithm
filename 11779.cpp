#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define INF 987654321
int dist[1001];
int from[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,x,y,c;
    cin>>N>>M;
    vector<pair<int,int>>v[1001];
    for(int i=0;i<M;i++)
    {
        cin>>x>>y>>c;
        v[x].push_back({y,c});
    }
    int start,end;
    cin>>start>>end;
    for(int i=1;i<=N;i++)
        dist[i]=INF;
    dist[start]=0;
    from[start]=-1;
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
                    from[dest]=cur;
                    q.push(dest);
                }
        }
    }
    cout<<dist[end]<<'\n';
    stack<int> s;
    while(end!=-1)
    {
        s.push(end);
        end=from[end];
    }
    cout<<s.size()<<'\n';
    while(!s.empty())
    {
        cout<<s.top()<<' ';
        s.pop();
    }
    
}