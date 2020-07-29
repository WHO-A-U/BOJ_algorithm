#include<iostream>
#include<vector>
using namespace std;
int D[1121][15];
bool num[1121];
vector<int> prime;
int ans=0,T,N,K;
int KS(int n,int k,int idx){
    if(n==0&&k==0){
        ans++;
        return 0;
    }
    if(n==0||k==0)
        return 0;
    for(int i=idx;i<prime.size();i++)
        if(n-prime[i]>=0)
            KS(n-prime[i],k-1,idx+1);
}
int main()
{
    for(int i=2;i<1121;i++)
        num[i]=true;
    for(int i=2;i<1121;i++)
    {
        if(!num[i])
            continue;
        bool isPrime=true;
        for(int j=2;j<i;j++)
            if(i%j==0){
                isPrime=false;
                break;
            }
        if(isPrime){
            prime.push_back(i);
            int j=i*2;
            while(j<1121)
            {
                num[j]=false;
                j+=i;
            }
        }
    }
    cin>>T;
    for(int i=0;i<1121;i++)
        for(int j=0;j<15;j++)
            D[i][j]=0;
    for(int i=0;i<T;i++)
    {
        cin>>N>>K;
        KS(N,K,0);
        cout<<ans<<'\n';
        ans=0;
    }
}