#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
vector<pair<int,int>> v[10001];
bool visit[10001];
int start,End,n,m;
bool isPossible(long long w)
{
    memset(visit,false,sizeof(visit));
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(x == End)
            return true;
        if(visit[x]==true)
            continue;
        visit[x]=true;
        for(int i=0;i<v[x].size();i++)
        {
            int target=v[x][i].first;
            int weight=v[x][i].second;
            if(weight>=w && visit[target]==false)
            {
                q.push(target);
            }
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y,z;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }
    cin>>start>>End;
    long long l=1;
    long long r=1000000000;
    long long mid;
    int ans=0;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(isPossible(mid)){
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    cout<<ans;
}