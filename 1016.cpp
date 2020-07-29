#include<iostream>
using namespace std;
bool check[10000001];
int main()
{
    long long min,max;
    cin>>min>>max;

    for(long long i=2;i*i<=max;i++)
    {
        long long start = i*i-min%(i*i);
        if(start == i*i)
            start=0;
        for(long long j=start;j<=max-min;j+=i*i)
            check[j]=true;
    }
    long long cnt=0;
    for(long long i=0;i<=max-min;i++)
        if(!check[i])
           {
                cnt++;
            }
    cout<<cnt;
}