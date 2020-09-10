#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,m,Truenum,x,y;
vector<int> TrueGuy;
vector<int> edge[51];
vector<int> party[51];
bool visit[51];
bool isFakeParty(int idx){
    // cout<<"****************\n";
    for(int i=0;i<party[idx].size();i++){
        // cout<<party[idx][i]<<" ";
        if(visit[party[idx][i]]==true)
            return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    cin>>Truenum;
    for(int i=0;i<Truenum;i++){
        cin>>x;
        TrueGuy.push_back(x);
    }
    for(int i=0;i<m;i++){
        int num;
        cin>>num;
        for(int j=0;j<num;j++){
            cin>>x;
            party[i].push_back(x);    
        }
        for(int j=0;j<party[i].size();j++){
            for(int k=j+1;k<party[i].size();k++){
                int a = party[i][j];
                int b = party[i][k];
                edge[a].push_back(b);
                edge[b].push_back(a);
            }
        }
    }
    memset(visit,false,sizeof(visit));
    queue<int> q;
    for(int i=0;i<TrueGuy.size();i++){
        q.push(TrueGuy[i]);
        visit[TrueGuy[i]]=true;
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<edge[cur].size();i++){
            int next = edge[cur][i];
            if(!visit[next]){
                visit[next]=true;
                q.push(next);
            }
        }
    }
    // cout<<"**************\n";
    // for(int i=0;i<7;i++){
    //     cout<<visit[i]<<" ";
    // }
    // cout<<"**************\n";
    int ans=0;
    for(int i=0;i<m;i++){
        if(isFakeParty(i))
            ans++;
    }
    cout<<ans;
}