#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int num[101];
bool v[101];
vector<int> getScore(int idx){
    vector<int> ret;
    if(v[idx])return ret;
    int cur = idx;
    bool visit[101];
    memset(visit,false,sizeof(visit));
    while(1){
        visit[cur]=true;
        cur = num[cur];
        if(cur==idx){
            break;
        }
        if(visit[cur]||v[cur]){
            return ret;
        }
    }
    for(int i=0;i<101;i++){
        if(visit[i]){
            v[i]=true;
            ret.push_back(i);
        }
    }
    return ret;
}
int main(){
    int n,x;
    vector<int> ans;
    memset(v,false,sizeof(v));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    for(int i=1;i<=n;i++){
        vector<int> tmp = getScore(i);
        for(int j=0;j<tmp.size();j++){
            ans.push_back(tmp[j]);
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
}