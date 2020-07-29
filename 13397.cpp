#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int arr[5001];
int sizeOfM(int x){
    int mini=arr[0];
    int maxi=arr[0];
    int M=1;
    for(int i=0;i<n;i++)
    {
        if(mini>arr[i])mini=arr[i];
        if(maxi<arr[i])maxi=arr[i];
        if(maxi-mini>x){
            mini=maxi=arr[i];
            M++;}
    }
    return M;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int l=0,r=10000;
    int mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(sizeOfM(mid)>m){
            l=mid+1;
        }
        else
            r=mid-1;
    }
    cout<<l;
}