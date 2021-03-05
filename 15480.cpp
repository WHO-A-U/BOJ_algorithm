#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX 100'001
#define MAX_D 17
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi =vector<vi>;
using vb = vector<bool>;
vvi edge(MAX);
int p[MAX][MAX_D];
int level[MAX];

int getNthParent(int node , int lev){
    int cur =node;
    int diff = lev;
    for(int i=MAX_D-1;i>=0;i--){
        if((diff-(1<<i))>=0){
            diff-=(1<<i);
            cur = p[cur][i];
        }
    }
    return cur;
}
int getLCA(int a,int b){
    while(level[a]!=level[b]){
        if(level[a]<level[b]){
                b = getNthParent(b,level[b]-level[a]);
            }else{
                a = getNthParent(a,level[a]-level[b]);
            }
    }
    while(a!=b){
        for(int i=MAX_D-1;i>=0;i--){
            if(p[a][i]>0&&p[b][i]>0&&p[a][i]!=p[b][i]){
                a=p[a][i];
                b=p[b][i];
                break;
            }
        }
        if(p[a][0]==p[b][0]){
            a=p[a][0];
            b=p[b][0];
            break;
        }
    }
    return a;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,r,a,b;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    vb visit(n+1,false);
    queue<pii> q;
    q.push({1,1});
    level[1]=1;
    visit[1]=true;

    while(!q.empty()){
        int cur = q.front().first;
        int lv = q.front().second;

        q.pop();
        for(int next : edge[cur]){
            if(visit[next])
                p[cur][0] = next;
            else{
                visit[next]=true;
                level[next]=lv+1;
                q.push({next,lv+1});
            }
        }
    }

    for(int j=1;j<MAX_D;j++){
        for(int i=1;i<=n;i++){
            if(p[i][j-1]>0)
                p[i][j] = p[p[i][j-1]][j-1];
        }
    }


    cin>>m;
    int ac,bc,cc,ans;
    while(m--){
        cin>>r>>a>>b;
        ac = getLCA(r,a);
        bc = getLCA(r,b);
        ans = level[ac]>level[bc]?ac:bc;
        cc = getLCA(a,b);
        ans = level[ans]>level[cc]?ans:cc;
        cout<<ans<<"\n";
    }  

    
}