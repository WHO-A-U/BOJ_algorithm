#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
int n;
int population[11];
vector<int> e[11];
vector<int> red;
vector<int> blue;
int ans=0x3f3f3f3f;
void cal(){
    if(red.size()==0||blue.size()==0)
        return ;
    bool v[11];
    memset(v,false,sizeof(v));
    int color[11]; //red :1  blue : 2
    for(int i=0;i<red.size();i++){
        color[red[i]]=1;
    }
    for(int i=0;i<blue.size();i++){
        color[blue[i]]=2;
    }

    queue <int> q;
    q.push(red[0]);
    v[red[0]]=true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<e[cur].size();i++){
            int next = e[cur][i];
            if(!v[next]&&color[next]==1){
                v[next]=true;
                q.push(next);
            }
        }
    }
    q.push(blue[0]);
    v[blue[0]]=true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<e[cur].size();i++){
            int next = e[cur][i];
            if(!v[next]&&color[next]==2){
                v[next]=true;
                q.push(next);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!v[i])return;
    }
    int redTeam =0,blueTeam=0;
    for(int i=0;i<red.size();i++){
        redTeam+=population[red[i]];
    }
    for(int i=0;i<blue.size();i++){
        blueTeam+=population[blue[i]];
    }
    ans = min(ans,abs(redTeam-blueTeam));
}
void divide(int cnt){
    if(cnt==n+1){
        cal();
        return ;
    }
    red.push_back(cnt);
    divide(cnt+1);
    red.pop_back();
    blue.push_back(cnt);
    divide(cnt+1);
    blue.pop_back();
    return;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>population[i];
    }
    for(int i=1;i<=n;i++){
        int deg,x;
        cin>>deg;
        for(int j=0;j<deg;j++){
            cin>>x;
            e[i].push_back(x);
        }
    }
    divide(1);
    cout<<(ans==0x3f3f3f3f?-1:ans);
}