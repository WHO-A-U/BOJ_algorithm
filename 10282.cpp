#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
vector<pair<int,int>>vec[10001];
int dist[10001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        int n,d,c;
        cin>>n>>d>>c;
        int a,b,s;
        for(int i=1;i<=n;i++)
            dist[i]=INF;
        for(int i=1;i<=n;i++)
            vec[i].clear();
        for(int i=0;i<d;i++)
        {
            cin>>a>>b>>s;
            vec[b].push_back({a,s});
        }
        queue<int>q;
        dist[c]=0;
        q.push(c);
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(int i=0;i<vec[x].size();i++)
            {
                if(dist[vec[x][i].first]>dist[x]+vec[x][i].second){
                    dist[vec[x][i].first]=dist[x]+vec[x][i].second;
                    q.push(vec[x][i].first);
                }
            }
        }
        int ans=0;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]!=INF)
            {
                cnt++;
                ans=max(ans,dist[i]);
            }
        }
        cout<<cnt<<" "<<ans<<'\n';
    }
}