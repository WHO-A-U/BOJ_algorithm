#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> e[101001];
int d[101001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,m;
    cin>>n>>k>>m;  //  n => 역개수  k=>한개의 하이퍼링크당  다리수 m=> 하이퍼링크 개수
    for(int i=1;i<=m;i++){
        int x;
        for(int j=0;j<k;j++){
            cin>>x;
            e[x].push_back(i+n);
            e[i+n].push_back(x);
        }
    }
    for(int i=1;i<=n+m;i++){
        d[i]=987654321;
    }
    queue<int>q;
    q.push(1);
    d[1]=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<e[cur].size();i++){
            int tmp;
            int pre = e[cur][i];
            if(pre>n)tmp=0;
            else tmp=1;
            if(d[pre]>d[cur]+tmp){
                d[pre]=d[cur]+tmp;
                q.push(pre);
            }
        }
    }
    if(d[n]==987654321)
        cout<<"-1";
    else
        cout<<d[n]+1;
}