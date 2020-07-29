#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long N,M;
int ride[10001];
long long TimeBinarySearch(void){
    long long l=0;
    long long r=2000000000LL*1000000LL;
    long long res=-1;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        long long children=M;
        for(int i=0;i<M;i++)
            children+=mid/ride[i];
        if(children>=N)
        {
            res=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return res;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<M;i++)
    {
        cin>>ride[i];
    }
    if(N<=M)
    {
        cout<<N<<endl;
        return 0;
    }
    long long time=TimeBinarySearch();
    long long children=M;
    for(int i=0;i<M;i++)
    {
        children+=(time-1)/ride[i];
    }
    for(int i=0;i<M;i++)
    {
        if(!(time%ride[i]))
            children++;
        if(children==N)
        {
            cout<<i+1;
            break;
        }
    }
    return 0;
}