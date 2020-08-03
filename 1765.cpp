#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
vector<int> E[1001];
vector<int> F[1001];
int team[1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    char s;
    int a,b;
    for(int i=1;i<=n;i++)
        team[i]=-1;
    for(int i=0;i<m;i++){
        cin>>s>>a>>b;
        if(s=='F'){
            F[a].push_back(b);
            F[b].push_back(a);

        }
        else{
            E[a].push_back(b);
            E[b].push_back(a);
        }
    }
    for(int i=1;i<=n;i++){
        if(team[i]==-1)
            team[i]=i;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int cur=q.front();
            int curteam=team[cur];
            q.pop();
            for(int j=0;j<F[cur].size();j++){
                if(team[F[cur][j]]==-1){
                    q.push(F[cur][j]);
                    team[F[cur][j]]=curteam;
                }
            }
        }
        queue<pair<int,int>>eq;
        for(int j=0;j<E[i].size();j++){
            eq.push({i,E[i][j]});
        }
        while(!eq.empty()){
            int pre=eq.front().first;
            int cur=eq.front().second;
            int preteam=team[pre];
            eq.pop();
            for(int j=0;j<E[cur].size();j++){
                if(team[E[cur][j]]==-1){
                    eq.push({cur,E[cur][j]});
                    team[E[cur][j]]=preteam;
                }
            }
        }
    }
    // for(int i=1;i<=n;i++)
    //     cout<<team[i]<<" ";
    set <int> teams;
    for(int i=1;i<=n;i++)
        teams.insert(team[i]);
    cout<<teams.size();

}