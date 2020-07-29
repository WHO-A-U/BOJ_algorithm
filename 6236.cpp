#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> needs;
int cal(int n){
    int cnt=0;
    int cur=0;
    for(int i=0;i<needs.size();i++)
    {
        if(needs[i]>cur){
            cnt++;      
            cur=n-needs[i];
        }
        else{
            cur-=needs[i];
        }
    }
    return cnt;
    //총 인출 횟수 반환한다
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,x;
    cin>>N>>M;
    int needssum=0;
    int maxneed=0;
    for(int i=0;i<N;i++){
        cin>>x;
        needssum+=x;
        maxneed=max(maxneed,x);
        needs.push_back(x);
    }
    int low=1;
    int high=needssum;
    int ans;
    int mid=0;
    while(low<=high){
        mid=(low+high)/2;
        if(mid<maxneed){
            low=mid+1;
            continue;
        }
        int temp=cal(mid);
        if(temp>M){
            low=mid+1;
        }
        else{
            ans=mid;
            high=mid-1;
        }
    }
    cout<<ans;
}