#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
vector<pair<int,int>> v[200];
vector<int> course[200];
int dist[201];
int ans[201][201];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,a,b,c;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for(int i=1;i<=n;i++)
    {
        
        for(int j=1;j<=n;j++)
            {
                course[j].clear();
                dist[j]=INF;
                }
        dist[i]=0;
        queue<int> q;
        course[i].push_back(i);
        q.push(i);
        while(!q.empty())
        {
            int cnt=q.front();
            q.pop();
            for(int k=0;k<v[cnt].size();k++)
            {
                int next = v[cnt][k].first;
                int cost=v[cnt][k].second;
                if(dist[next]>dist[cnt]+cost)
                {
                    dist[next]=dist[cnt]+cost;
                    course[next].clear();
                    course[next].resize(course[cnt].size());
                    course[next].assign(course[cnt].begin(),course[cnt].end());
                    course[next].push_back(next);
                    q.push(next);
                }
            }
        }
        for(int k=1;k<=n;k++)
        {
            ans[i][k]=course[k][1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            {
                if(i==j)
                    cout<<"- ";
                else
                    cout<<ans[i][j]<<" ";    
            }
        cout<<'\n';
    }
}