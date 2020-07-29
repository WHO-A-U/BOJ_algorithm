#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> home;
int n,c,x;
bool ispos(int dist){
    int cnt=1;
    int bef=home[0];
    for(int i=0;i<home.size();i++)
    {
        if(home[i]-bef>=dist){
            cnt++;
            bef=home[i];
        }
    }
    return cnt>=c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>c;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        home.push_back(x);
    }
    sort(home.begin(),home.end());
    int low=1;
    int high=home[n-1]-home[0];
    int ans=1;
    while(low<=high){
        int mid=(low+high)/2;
        if(ispos(mid)){
            low=mid+1;
            ans=max(ans,mid);
        }
        else
        {
            high=mid-1;
        }
        
    }
    cout<<ans;
}