#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ft first
#define sd second
using namespace std;
using pii = pair<int, int>;
using vpii = vector<pii>;
int d[1001][1001];
int p[1001][1001];
int n,m,y,x;
vpii cord;
int getDist(pii i,pii j){
    return abs(i.ft-j.ft)+abs(i.sd-j.sd);
}
int go(int a,int b){
    if(a==m||b==m){
        return d[a][b]=0;
    }
    int &ret = d[a][b];

    if(ret!=-1)
        return ret;


    pii curA=cord[a],curB=cord[b];

    if(a==0) curA = {1,1};
    if(b==0) curB = {n,n};
    int next = max(a,b)+1;

    int v1 = go(next,b)+getDist(curA,cord[next]);
    int v2 = go(a,next)+getDist(curB,cord[next]);
    
    ret = min(v1,v2);

    if(v1<v2)
        p[a][b]=1;
    else
        p[a][b]=2;

    return ret;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   
   cin>>n>>m;

   memset(d,-1,sizeof(d));
   memset(p,-1,sizeof(p));
   cord.assign(m+1,{});

   for(int i=1;i<=m;i++){
       cin>>y>>x;
       cord[i]={y,x};
   }

    cout<<go(0,0)<<"\n";
    
    int cur,l=0,r=0;

    while(l!=m&&r!=m){
        cur = p[l][r];
        cout<<cur<<"\n";
        if(cur==1)
            l = max(l,r)+1;
        else
            r = max(l,r)+1;
    }
    

}