#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
int dist[20001];
vector<int>g[20001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v,e,a,b;
    cin>>v>>e;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
       g[a].push_back(b);
       g[b].push_back(a);
    }
    for(int i=1;i<=v;i++)
        dist[i]=INF;
    queue<int> q;
    q.push(1);
    dist[1]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<g[x].size();i++)
        {
            int k=g[x][i];
            if(dist[k]>dist[x]+1)
            {
                dist[k]=dist[x]+1;
                q.push(k);
            }
        }
    }
    int maxval=0;
    for(int i=1;i<=v;i++)
        maxval=max(maxval,dist[i]);
    vector<int> ans;
    for(int i=1;i<=v;i++)
        if(dist[i]==maxval)
            ans.push_back(i);
    sort(ans.begin(),ans.end());
    cout<<ans[0]<<" "<<maxval<<" "<<ans.size();

}