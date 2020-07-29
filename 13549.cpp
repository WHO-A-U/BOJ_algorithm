#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> dist;
    dist.assign(100001,0x3f3f3f);
    dist[n]=0;
    queue<int> q;
    q.push(n);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(x-1>=0 && dist[x-1]>dist[x]+1)
        {
            dist[x-1]=dist[x]+1;
            q.push(x-1);
        }
        if(x+1<=100000 && dist[x+1]>dist[x]+1)
        {
            dist[x+1]=dist[x]+1;
            q.push(x+1);
        }
        if(x*2<=100000 && dist[2*x]>dist[x])
        {
            dist[x*2]=dist[x];
            q.push(x*2);
        }
    }
    cout<<dist[k];


}