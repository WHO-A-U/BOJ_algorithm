#include<iostream>
#include<cstring>
#include<map>
using namespace std;
int t,k,a,b;
int p[200001];
int n[200001];
int Find(int x){
    if(p[x]==x)
        return x;
    return p[x]=Find(p[x]);    
}
int Union(int x,int y){
    x=Find(x);
    y=Find(y);
    if(x!=y)
    {
        p[x]=y;
        n[y]+=n[x];
        n[x]=1;
    }
    return n[y];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    string A1,A2;
    while(t--){
       cin>>k;
       for(int i=0;i<2*k;i++)
       {
           p[i]=i;
           n[i]=1;
       }
       map<string,int> m; 
       int cnt=0;
       for(int i=0;i<k;i++)
       {
           cin>>A1>>A2;
           if(m.count(A1)==0){
               m[A1]=cnt++;
           }
           a=m[A1];
           if(m.count(A2)==0){
               m[A2]=cnt++;
           }
           b=m[A2];
           cout<<Union(a,b)<<"\n";
       }
    }
}