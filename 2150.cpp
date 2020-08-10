#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
#define MAX 10001
using namespace std;
int id=0;
int d[MAX];
bool finished[MAX];
vector<int> e[MAX];
vector<vector<int>> SCC;
stack<int> s;
int dfs(int cur){
    d[cur]=++id;
    s.push(cur);
    int p=d[cur];
    for(int i=0;i<e[cur].size();i++){
        int next=e[cur][i];
        if(d[next]==0){
            p=min(p,dfs(next));
        }
        else if(!finished[next]){
            p=min(p,d[next]);
        }
    }
    if(p==d[cur]){
        vector<int> tmp;
        while(1){
            int t=s.top();
            s.pop();
            tmp.push_back(t);
            finished[t]=true;
            if(cur==t)
                break;
        }
        SCC.push_back(tmp);
    }
    return p;
}
bool cmp(vector<int> &a,vector<int> &b){
    if(a[0]<b[0])
        return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        e[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(d[i]==0)
            dfs(i);
    }
    for(int i=0;i<SCC.size();i++){
        sort(SCC[i].begin(),SCC[i].end());
    }
    sort(SCC.begin(),SCC.end(),cmp);
    cout<<SCC.size()<<'\n';
    for(int i=0;i<SCC.size();i++){
        for(int j=0;j<SCC[i].size();j++){
            cout<<SCC[i][j]<<" ";
        }
        cout<<"-1\n";
    }
}