#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> cost;
vector<pair<int,int>> stuff;
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T,M,x,y;
    cin>>T>>M;
    cost.assign(M+1,0);
    for(int i=0;i<T;i++)
    {
        cin>>x>>y;
        stuff.push_back({x,y});
    }
    for(int i=0;i<stuff.size();i++)
    {   
        int weight=stuff[i].first;
        int value=stuff[i].second;
        for(int j=M;j>=0;j--)
            if(j==0 || cost[j]!=0)
                if(weight + j <=M)
                    cost[j+weight]=max(cost[j]+value,cost[j+weight]);
    }
    int ans=0;
    for(int i=1;i<=M;i++)
        ans=max(ans,cost[i]);
    cout<<ans;
}