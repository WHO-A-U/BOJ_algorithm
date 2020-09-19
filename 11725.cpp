#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int d[100001];
vector<int> v[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,y;
    memset(d,-1,sizeof(d));
    d[1]=1;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    d[1]=1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i];
            if(d[next]==-1){
                d[next]=cur;
                q.push(next);
            }
        }
    }
    for(int i=2;i<=n;i++){
        cout<<d[i]<<"\n";
    }
}
