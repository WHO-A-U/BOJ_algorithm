#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int d[1001][1001];
int p[1001];
int Find(int x);
void Union(int x, int y)
{
    x=Find(x);
    y=Find(y);
    if(x==y)
        return ;
    else 
    {
        if(p[x]>p[y])
            p[y]=x;
        else 
            p[x]=y;
    }
    return ;
}
int Find(int x)
{
    if(x==p[x])
        return x;
    else 
        return p[x]=Find(p[x]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(n==1)
        {
            cout<<"0";
            return 0;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>d[i][j];
        }
    priority_queue<pair<int,pair<int,int>>>q;
    for(int i=1;i<=n;i++)
        p[i]=i;
    for(int i=2;i<=n;i++){
        q.push({-d[1][i],{1,i}});
    }
    long long ans=0;
    while(!q.empty()){
        int cost=-q.top().first;
        int from=q.top().second.first;
        int to=q.top().second.second;
        q.pop();
        if(Find(from)!=Find(to)){
            Union(from,to);
            ans+=cost;
            for(int i=1;i<=n;i++)
            {
                if(i==from)
                    continue;
                q.push({-d[to][i],{to,i}});
            }
        }
    }
    cout<<ans;

}                            