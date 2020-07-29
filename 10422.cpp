#include<iostream>
#include<vector>
using namespace std;
long long d[2501];
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    d[0]=1;
    for(int i=1;i<=2500;i++)
    {
        for(int j=1;j<=i;j++)
        {
            d[i]=d[i]+(d[j-1]*d[i-j]);
            d[i]%=1000000007;
        }
        d[i]%=1000000007;
    }
    int t,x;
    cin>>t;
    while(t--)
    {
        cin>>x;
        cout<<(x%2==0?d[x/2]:0)<<'\n';
    }
}