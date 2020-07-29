#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[101][101];
bool visit[101][101];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,minv=200,maxv=0;
bool isPossible(int minval,int maxval)
{
    if(arr[1][1]<minval||arr[1][1]>maxval)
        return false;
    memset(visit,false,sizeof(visit));
    queue<pair<int,int>> q;
    q.push({1,1});
    visit[1][1]=true;
    while(!q.empty())
    {
        auto x=q.front();
        q.pop();
        if(x.first==n && x.second==n)
            return true;
        for(int i=0;i<4;i++)
        {
            int nx=x.first+dx[i];
            int ny=x.second+dy[i];
            if(nx>=1 && nx<=n &&ny>=1 && ny<=n&&visit[nx][ny]==false)
            {
                if(arr[nx][ny]>=minval&&arr[nx][ny]<=maxval)
                  {
                    q.push({nx,ny});
                    visit[nx][ny]=true;
                  }
            }
        }
    }
    return false;
}
bool go(int bet)
{
    for(int x=0;x+bet<=200;x++)
    {
        if(isPossible(x,x+bet))
            return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int l=0;
    int r=200;
    int mid;
    int ans=200;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(go(mid)){
            r=mid-1;
            ans=min(ans,mid);
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans;
}