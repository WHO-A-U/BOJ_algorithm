#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
bool v[1001];
int d[1001][1001];
priority_queue<pair<int,pair<int,int>>>q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,a,b,cost;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>cost;
        d[a][b]=d[b][a]=cost;
    }
    v[1]=true;;
    for(int i=2;i<=n;i++)
    {
        if(d[1][i]>0)
             q.push({-d[1][i],{1,i}});
    }
    int vertex=1;
    int ans=0;
    while(!q.empty())
    {
        int cost=-q.top().first;
        
        int x=q.top().second.first;
        int y=q.top().second.second;
        q.pop();
        if(v[x]==true&&v[y]==true)
            {
                if(q.empty())
                     break;
                continue;
            }
        else
        {
        ans+=cost;
        int idx=(v[y]==false?y:x);
        v[x]=v[y]=true;
        for(int i=1;i<=n;i++)
           {
               if(d[idx][i]>0&&v[i]==false)
                 q.push({-d[idx][i],{idx,i}});
           }
        
        }
    }
    cout<<ans;
}