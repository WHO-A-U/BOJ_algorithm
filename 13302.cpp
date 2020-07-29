#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
#define INF 987654321
int t1=10000;
int t2=25000;
int t3=37000;
bool days[101];
int v[101][110];//110
int n,m;
int main()
{
    int x;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x;
        days[x]=true;
    }
    for(int i=0;i<101;i++)
        for(int j=0;j<110;j++)
            v[i][j]=INF;
    v[0][0]=0;
    //v[i][j]  i 번째 가지 완료 j개 쿠폰가지고 있는 상태
    for(int i=1;i<=n;i++)
    {
        if(days[i]==true){
            for(int j=0;j<=109;j++)
            {
                v[i][j]=min(v[i][j],v[i-1][j]);
            }
        }
        for(int j=0;j<=109;j++)
        {
            if(i-1>=0){
                if(j+3<=108&&v[i-1][j+3]!=INF){
                    v[i][j]=min(v[i][j],v[i-1][j+3]);
                }
                v[i][j]=min(v[i-1][j]+t1,v[i][j]);
            }
            if(i-3>=0){
                if(j>=1&&j+1<=109){
                    if(v[i-3][j-1]!=INF){
                    v[i][j]=min(v[i][j],v[i-3][j-1]+t2);
                    }
                }
            }
            if(i-5>=0){
                if(j>=2&&j+2<=109){
                    if(v[i-5][j-2]!=INF){
                    v[i][j]=min(v[i][j],v[i-5][j-2]+t3);}
                }
            }
        }
    }
    int ans=INF;
    for(int i=0;i<109;i++)
    {  
        ans=min(ans,v[n][i]);
    }
    cout<<ans<<endl;

    // for(int j=0;j<30;j++)
    // {
    //     for(int i=0;i<15;i++)
    //         printf("%09d ",v[i][j]);
    //     cout<<endl;
    // }
}