#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int> d[501];
int v[501][2];
bool visit[501];
int cnt;
void go(int x){
    for(int i=0;i<d[x].size();i++)
    {
        if(visit[d[x][i]]==false){
        visit[d[x][i]]=true;
        cnt++;
        v[d[x][i]][1]++;
        go(d[x][i]);
        }
    }
}
int main()
{
    int n,m,x,y;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        d[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
    {
        memset(visit,0,sizeof(visit));
        go(i);
        v[i][0]=cnt;
        cnt=0;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i][0]+v[i][1]==n-1)
        {
            ans++;
        }
    }
    cout<<ans;

}