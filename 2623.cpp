#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n,m,k,x,pre;
vector<int> ver[1001];
vector<int> ans;
int degree[1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>k;
        cin>>pre;
        for(int j=0;j<k-1;j++){
            degree[pre]++;
            cin>>x;
            ver[x].push_back(pre);
            pre=x;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(degree[i]==0)
            q.push(i);
    for(int i=1;i<=n;i++){
        if(q.empty()){
            break;
        }
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for(int next : ver[cur]){
            if(--degree[next]==0){
                q.push(next);
            }
        }
    }
    if(ans.size()==n){
        for(int i=ans.size()-1;i>=0;i--)
            cout<<ans[i]<<"\n";
    }
    else{
        cout<<0;
    }
}