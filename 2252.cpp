#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> v[32001];
int d[32001];
bool ordered[32001];
int main()
{
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        d[b]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(d[i]==0)
            q.push(i);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<v[x].size();i++)
        {
            d[v[x][i]]--;
            if(d[v[x][i]]==0)
                q.push(v[x][i]);
        }
        cout<<x<<" ";
        ordered[x]=true;
    }
    for(int i=1;i<=n;i++)
        if(ordered[i]==false)
            cout<<i<<" ";
}