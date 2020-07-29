#include<iostream>
#include<algorithm>
using namespace std;
//n(1¡Ân¡Â1,000,000), m(1¡Âm¡Â100,000)
int d[1000001];
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
bool isjoint(int a,int b)
{
    if(Find(a)==Find(b))
        return true;
    return false;
}
void Union(int a,int b)
{
    a=Find(a);
    b=Find(b);
    if(a!=b)
        d[b]=a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q,a,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        d[i]=i;
    for(int i=0;i<m;i++)
    {
        cin>>q>>a>>b;
        if(q==0)//union
            Union(a,b);
        else//find
        {
            if(isjoint(a,b))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
}
