#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
vector<pair<int,int>> ver[100001];
bool visit[100001];
queue<pair<int,int>> q;
int n,a,b,c;
int getRadius(){
    q.push({1,0});
    visit[1]=true;
    int minVal=0,idx;
    while(!q.empty()){
        int cur =q.front().first;
        int cost = q.front().second;
        if(minVal<cost){
            idx=cur;
            minVal=cost;
        }
        q.pop();
        for(int i=0;i<ver[cur].size();i++){
            int next = ver[cur][i].first;
            int dist = ver[cur][i].second;
            if(!visit[next]){
                visit[next]=true;
                q.push({next,cost+dist});
            }
        }
    }
    memset(visit,false,sizeof(visit));
    minVal=0;
    visit[idx]=true;
    q.push({ idx,0});
    while(!q.empty()){
        int cur = q.front().first;
        int cost = q.front().second;
        if(cost>minVal){
            minVal=cost;
        }
        q.pop();
        for(int i=0;i<ver[cur].size();i++){
            int next = ver[cur][i].first;
            int dist = ver[cur][i].second;
            if(!visit[next]){
                visit[next]=true;
                q.push({next,cost+dist});
            }
        }
    }
    return minVal;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        while(1){
            cin>>b;
            if(b==-1)break;
            cin>>c;
            ver[b].push_back({a,c});
            ver[a].push_back({b,c});
        }
    }
    cout<<getRadius();
}