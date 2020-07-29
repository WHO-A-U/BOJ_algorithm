#include<iostream>
using namespace std; 
int d[100001];
int Find(int x){
    if(d[x]==x)
        return x;
    return d[x]=Find(d[x]);
}
void Union(int a,int b){
    a=Find(a);
    b=Find(b);
    d[a]=b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int G,P,x,cnt=0;
    cin>>G>>P;
    for(int i=1;i<=G;i++)
        d[i]=i;
    for(int i=1;i<=P;i++)
    {
        cin>>x;
        int r=Find(x);
        if(r!=0){
            Union(r,r-1);
            cnt++;
        }
        else
            break;
    }
    cout<<cnt;
}
    
