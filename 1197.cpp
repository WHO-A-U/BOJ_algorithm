#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct e{
    int x,y,c;
    bool operator < (const e &tmp) const{
        return c<tmp.c;
    }
};
int p[10001];
int Find(int x)
{
    if(x==p[x])
        return x;
    else{
        return p[x]=Find(p[x]);
    }
}
void Union(int a,int b)
{
    a=Find(a);
    b=Find(b);
    p[b]=a;
}
vector<struct e> vec;
int main()
{
    int v,e,x,y,cost;
    cin>>v>>e;
    
    for(int i=1;i<=v;i++)
    {
        p[i]=i;
    }
    int ans=0;
    for(int i=0;i<e;i++)
    {
        cin>>x>>y>>cost;
        struct e tmp={x,y,cost};
        vec.push_back(tmp);
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<e;i++)
    {
        struct e tmp=vec[i];
        int nx=Find(tmp.x);
        int ny=Find(tmp.y);
        if(nx!=ny)
        {
            Union(nx,ny);
            ans+=tmp.c;
        }
    }
    cout<<ans;
    return 0;
}