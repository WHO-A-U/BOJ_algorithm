#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> v[10001];
vector<int> c[10001];
int d[10001];
int M[10001];
queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,m,a;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>m;
        M[i]=x;
        d[i]=m;
        for(int j=0;j<m;j++)
        {
            cin>>a;
            v[a].push_back(i);
            c[i].push_back(a);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(d[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        int maxtime=0;
        for(int i=0;i<c[tmp].size();i++)
        {
            maxtime=max(maxtime,M[c[tmp][i]]);
        }

        M[tmp]+=maxtime;
        for(int i=0;i<v[tmp].size();i++)
        {
            d[v[tmp][i]]--;
            if(d[v[tmp][i]]==0)
                q.push(v[tmp][i]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,M[i]);

    }
    cout<<ans;

}