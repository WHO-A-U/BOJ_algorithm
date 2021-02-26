#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
vector<int> e[100001];
bool visit[100001];
vector<int> tmp[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,y;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    memset(visit,false,sizeof(visit));
    queue<int> q;
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

    queue<int> seq;
    for(int i=0;i<n;i++){
        cin>>x;
        seq.push(x);
    }
    if(seq.front()!=1){
        cout<<"0";
        return 0;
    }
    seq.pop();
    q.push(1);
    bool flag;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        map<int,int> m;
        for(int next : e[cur] ){
            m[next]=1;
        }
        int cnt = e[cur].size();
        flag=true;
        for(int i=0;i<cnt;i++){
            int next_seq = seq.front();
            seq.pop();
            if(m[next_seq]==1){
                m[next_seq]=0;
                q.push(next_seq);
            }
            else{
                flag=false;
                break;
            }
        }
        if(!flag){
            break;
        }
    }
    cout<<flag?1:0;
}