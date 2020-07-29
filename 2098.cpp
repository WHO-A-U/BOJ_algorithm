#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int w[17][17];
int d[17][1<<17];
int n;
int tsp(int node,int visit){
    if(visit == (1<<n)-1)
        if(w[node][1]!=0)
            return w[node][1];
    int &val=d[node][visit];
    if(val!=0)
        return val;
    val=0x3f3f3f;
    for(int i=1;i<=n;i++)
        if((visit&(1<<(i-1)))==0 &&(w[node][i]!=0))
            val=min(val,w[node][i]+tsp(i,visit|(1<<(i-1)) ) ) ;
    return val;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>w[i][j];
    cout<<tsp(1,1);
    
}
