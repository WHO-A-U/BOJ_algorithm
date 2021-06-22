#include<iostream>
#include<queue>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int d[11][11];
int dist[11][1<<11];
int main(){
    int n,s;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int z=0;z<(1<<n);z++){
            dist[i][z]=INF;
        }
    }

    dist[s][(1<<s)]=0;

    queue<pair<int,int>> q;
    q.push({s,(1<<s)});
    while(!q.empty()){
        int cur = q.front().first;
        int bitmask = q.front().second;

        q.pop();
        int curCost = dist[cur][bitmask];
        for(int next=0;next<n;next++){
            int nextBitMask = bitmask|(1<<next);

            if(dist[next][nextBitMask] > curCost + d[cur][next]){
                dist[next][nextBitMask] = curCost + d[cur][next];

                q.push({next,nextBitMask});
            }
        }
    }
    int minVal = INF;
    for(int i=0;i<n;i++){
        minVal = min(minVal , dist[i][(1<<n)-1]);
    }
    cout<<minVal;
}
