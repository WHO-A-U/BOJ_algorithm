#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int d[51][51];
vector<int>ans;
int president=0x3f3f3f;
int val[51];
int main()
{
    int n,a,b,cnt=0;;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            if(i!=j)
                d[i][j]=0x3f3f3f;
    }
    while(true)
    {
        cin>>a>>b;
        if(a==-1&&b==-1)
            break;
        d[a][b]=d[b][a]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(d[i][j]>d[i][k]+d[k][j])
                    d[i][j]=d[i][k]+d[k][j];
                if(k==n)
                    val[i]=max(val[i],d[i][j]);
            }
        }
    }
    for(int i=1;i<=n;i++)
        president=min(president,val[i]);
 
    for(int i=1;i<=n;i++)
        if(president==val[i])
        {
            cnt++;
            ans.push_back(i);
        }
    sort(ans.begin(),ans.end());
    cout<<president<<" "<<cnt<<'\n';
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}