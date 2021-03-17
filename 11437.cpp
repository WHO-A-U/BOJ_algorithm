#include<bits/stdc++.h>
#define MAX 50001
#define MAX_D 17
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vb =vector<bool>;
int d[MAX][MAX_D];
int depth[MAX];
int getHigher(int c , int df){
    int cur = c;
    int diff = df;
    for(int i=MAX_D-1;i>=0;i--){
        if((diff-(1<<i))>=0){
            diff-=(1<<i);
            cur = d[cur][i];
        }
    }
    return cur;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,x,y;
    cin>>n;

    vvi e(n+1);
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    vb visit(n+1,false);
    queue<pii> q;
    q.push({1,1});
    visit[1]=true;
    depth[1]=1;
    while(!q.empty()){
        int cur = q.front().first;
        int dep = q.front().second;
        q.pop();
        for(auto next : e[cur]){
            if(!visit[next]){
                visit[next]=true;
                depth[next]=dep+1;
                q.push({next,dep+1});
            }else{
                d[cur][0]=next;
            }
        }
    }

    for(int j=1;j<MAX_D;j++){
        for(int i=1;i<=n;i++){
            if(d[i][j-1]>0)
                d[i][j] = d[d[i][j-1]][j-1];
        }
    }

    cin>>m;
    while(m--){
        cin>>x>>y;
        while(depth[x]!=depth[y]){
            int diff = abs(depth[x]-depth[y]);
            if(depth[x]<depth[y]){
                y = getHigher(y,diff);
            }else{
                x = getHigher(x,diff);
            }
        }

        while(x!=y){
            for(int i=MAX_D-1;i>=0;i--){
                if(d[x][i]>0&&d[y][i]>0&&d[x][i]!=d[y][i]){
                    x=d[x][i];
                    y=d[y][i];
                    break;
                }
            }
            if(d[x][0]==d[y][0]){
                x=d[x][0];
                break;
            }
        }
        cout<<x<<"\n";
    }
}