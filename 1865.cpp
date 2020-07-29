#include<iostream>
#include<vector>
using namespace std;
const int INF = 987654321;
int dist[501];
int main()
{
    int T,n,m,w;
    cin>>T;
    while(T--){
        vector<pair<int,int>>adj[501];
        cin>>n>>m>>w;
        for(int i=1;i<=n;i++)
            dist[i]=INF;
        dist[1]=0;
        int a,b,c;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>c;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        for(int i=0;i<w;i++)
        {
            cin>>a>>b>>c;
            adj[a].push_back({b,-c});
        }
        bool ans=true;
        int cnt=0;
        while(ans && cnt!=n){
            ans=false;
            cnt++;
            for(int j=1;j<=n;j++)
            {
                for(int k=0;k<adj[j].size();k++)
                {
                    int next=adj[j][k].first;
                    int val=adj[j][k].second;
                    if(dist[next]>dist[j]+val)
                    {
                        dist[next]=dist[j]+val;
                        ans=true;
                    }
                }
            }
        }
        if(cnt==n)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}