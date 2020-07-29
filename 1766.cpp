#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool visit[32001];
int d[32001];
vector<int> v[32001];
priority_queue<int> q;
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
    for(int i=1;i<=n;i++)
    {
        if(d[i]==0)
            q.push(-i);
    }
    for(int k=0;k<n;k++)
    {
        int x=-q.top();
        q.pop();
        cout<<x<<" ";
        for(int i=0;i<v[x].size();i++)
        {
            d[v[x][i]]--;
            if(d[v[x][i]]==0)
                q.push(-v[x][i]);
        }
    }
    return 0;
}