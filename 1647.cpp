#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<pair<int,int>> v[100001];    //v[from] => {to , val}
priority_queue<pair<int,pair<int,int>>> pq; // q => {val, {from,to}}
bool visit[100001];
int main()
{
    int n,m,a,b,c;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    visit[1]=true;
    for(int i=0;i<v[1].size();i++)
    {
        pq.push({-v[1][i].second,{1,v[1][i].first}});
    }
    long long ans=0;
    int maxlen=0;
    while(!pq.empty()){
        int val=-pq.top().first;
        int from = pq.top().second.first;
        int to = pq.top().second.second;
        pq.pop();
        if(visit[to]==true)
            continue;
        else{
            ans+=val;
            maxlen=max(val,maxlen);
            visit[to]=true;
            for(int i=0;i<v[to].size();i++)
            {
                if(visit[v[to][i].first]==false)
                {
                    pq.push( {-v[to][i].second,{to,v[to][i].first  }});
                }
            }
        }
    }
    cout<<ans-maxlen;
}