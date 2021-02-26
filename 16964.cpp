#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
vector<int> e[100001];
bool visit[100001];
vector<int> tmp[100001];
bool flag;
queue<int> q;
void go(int cur){
    map<int,int> m;
    for(int next : e[cur]){
        m[next]=1;
    }
    int cnt = e[cur].size();
    for(int i=0;i<cnt;i++){
        int next = q.front();
        q.pop();
        if(m[next]==1){
            m[next]=0;
            go(next);
        }else{
            flag=false;
            break;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    flag=true;
    int n,x,y;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    memset(visit,false,sizeof(visit));
    q.push(1);
    visit[1]=true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int next : e[cur]){
            if(!visit[next]){
                visit[next]=true;
                tmp[cur].push_back(next);
                q.push(next);
            }
        }
    }
    for(int i=1;i<=n;i++){
        e[i]=tmp[i];
    }
    
    for(int i=0;i<n;i++){
        cin>>x;
        q.push(x);
    }
    if(q.front()!=1){
        cout<<"0";
        return 0;
    }
    q.pop();
    go(1);
   
    cout<<flag?1:0;
}