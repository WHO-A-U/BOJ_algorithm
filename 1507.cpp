#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 987654321
int dist[21][21];
bool v[21][21];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>dist[i][j];
        }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(i!=k && i!=j && k!=j){
                    if(dist[i][j]>dist[i][k]+dist[k][j])
                    {
                        cout<<"-1";
                        return 0;
                    }
                    if(dist[i][j]==dist[i][k]+dist[k][j])
                        v[i][j]=true;
                }
            }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
           if(v[i][j]==false)
                 ans+=dist[i][j];
    }
    cout<<ans/2;
}