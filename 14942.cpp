#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 100001
#define MAX_D 17
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;

vvpii edge(MAX);
vvpii upEdge(MAX);

int d[MAX][MAX_D][2]; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vi energy(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>energy[i];
    }

    int a,b,c;
    for(int i=0;i<n-1;i++){
        cin>>a>>b>>c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }

    vb visit(n+1,false);
    visit[1]=true;
    
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto next : edge[cur]){
            int nextNum = next.first;
            int cost = next.second;
            if(visit[nextNum]){
                upEdge[cur].push_back({nextNum,cost});
            }else{
                visit[nextNum]=true;
                q.push(nextNum);
            }
        }
    }





    for(int i=1;i<=n;i++){
        if(!upEdge[i].empty()){
            d[i][0][0]=upEdge[i][0].first;
            d[i][0][1]=upEdge[i][0].second;
        }
    }

    for(int j=1;j<MAX_D;j++){
        for(int i=1;i<=n;i++){
            if(d[i][j-1][0]>0){
                d[i][j][0] = d[d[i][j-1][0]][j-1][0];
                d[i][j][1] = d[d[i][j-1][0]][j-1][1]+d[i][j-1][1];
            }
        }
    }


    for(int i=1;i<=n;i++){
        int cur = i;
        int eng = energy[i];
        for(int j=MAX_D-1;j>=0;j--){
            if(d[cur][j][0]>0&&d[cur][j][1]<=eng){
                eng-=d[cur][j][1];
                cur = d[cur][j][0];
            }
            if(cur==1)break;
        }
        cout<<cur<<"\n";
    }



}
