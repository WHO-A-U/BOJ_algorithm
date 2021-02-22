#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
vector<pair <int,int> > e[200001];
vector<pair<int,int> > tmp[200001];
bool v[200001];
int ans1,ans2;
int getGigaNode(int idx){
    while(e[idx].size()==1){
        if(v[idx]||v[e[idx][0].first]){
            break;
        }
        v[idx]=true;
        ans1+=e[idx][0].second;
        idx = e[idx][0].first;
    }
    return idx;
}
void getLongestBranch(int idx,int val){
    if(e[idx].size()==0){
        ans2 = max(ans2 , val);
        return ;
    }
    for(int i=0;i<e[idx].size();i++){
        int next = e[idx][i].first;
        int dist = e[idx][i].second;
        if(!v[next]){
            v[next]=true;
            getLongestBranch(next,val+dist);
        }
    }
}
void go(int idx){
    for(int i=0;i<e[idx].size();i++){
        int next = e[idx][i].first;
        if(!v[next]){
            v[next]=true;
            tmp[idx].push_back(e[idx][i]);
            go(next);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ans1=0,ans2=0;
    int n,r,a,b,dist;
    cin>>n>>r;
    memset(v,false,sizeof(v));
    for(int i=0;i<n-1;i++){
        cin>>a>>b>>dist;
        e[a].push_back(make_pair(b,dist));
        e[b].push_back(make_pair(a,dist));
    }
    v[r]=true;
    go(r);
    for(int i=1;i<=n;i++){
        e[i]=tmp[i];
    }
    memset(v,false,sizeof(v));
    int gigaNode=getGigaNode(r);
    getLongestBranch(gigaNode,0);
    cout<<ans1<<" "<<ans2;
}