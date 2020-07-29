#include<iostream>
#include<vector>
using namespace std;
const vector<vector<int>> mul(vector<vector<int>> &a,vector<vector<int>> &b)
{
    int n=a.size();
    vector<vector<int>> tmp(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                tmp[i][j]+=(a[i][k]*b[k][j]);
            }
            tmp[i][j]%=1000;
        }
    }
    return tmp;
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    long long pow;
    cin>>N>>pow;
    vector<vector<int>> A(N,vector<int>(N));
    vector<vector<int>> ans(N,vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin>>A[i][j];
        }
        ans[i][i]=1;
    }
    while(pow>0)
    {
        if(pow%2==1)
            ans=mul(ans,A);
        A=mul(A,A);
        pow/=2;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';
    }
}