#include<iostream>
using namespace std;
int d[101];
int Find(int x)
{
    if(x==d[x])
        return x;
    else
    {
        int p=Find(d[x]);
        return d[x]=p;
    }
    
}
void Union(int a,int b)
{
    a=Find(a);
    b=Find(b);
    if(a==1)
        d[b]=1;
    else if(b==1)
        d[a]=1;
    else if(a!=b)
            d[b]=a;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        d[i]=i;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        Union(a,b);
    }
    int ans=0;
    for(int i=2;i<=n;i++)
       if(d[1]==Find(i))
            ans++;
    cout<<ans;

}