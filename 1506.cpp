#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#include<stack>
#define MAX 501
using namespace std;
int cost[MAX];
vector<vector<int>> SCC;
vector<int> edge[MAX];
int id,d[MAX];
bool finished[MAX];
stack<int>s;
int dfs(int x){
    d[x]=++id;
    s.push(x);

    int parent = d[x];
    for(int i=0;i<edge[x].size();i++){
        int next=edge[x][i];
        if(d[next]==0){
            parent=min(parent,dfs(next));
        }
        else if(!finished[next])
                parent=min(parent,d[next]);
    }

    if(parent==d[x]){
        vector<int> tmp;
        while(1){
            int t=s.top();
            s.pop();
            tmp.push_back(cost[t]);
            finished[t]=true;
            if(t==x)break;
        }
        SCC.push_back(tmp);
    }
    return parent;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }
    string str;
    for(int i=1;i<=n;i++){
        cin>>str;
        for(int j=0;j<n;j++){
            if(str[j]=='1'){
                edge[i].push_back(j+1);
            }
        }
    }
    for(int i=1;i<=n;i++){
      if(d[i]==0)
        dfs(i);
    }
    for(int i=0;i<SCC.size();i++){
        sort(SCC[i].begin(),SCC[i].end());
        // for(int j=0;j<SCC[i].size();j++){
        //     cout<<SCC[i][j]<<" ";
        // }
        // cout<<endl;
    }
    long long ans=0;
    for(int i=0;i<SCC.size();i++){
        ans+=SCC[i][0];
    }
    cout<<ans;
    
}