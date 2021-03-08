#include<iostream>
#include<queue>
#include<vector>
#define MAX 100001
#define INF 0x3f3f3f3f
using namespace std;
int d[MAX];
int cnt=0,minVal=INF;
int main(){
    int start,end;
    cin>>start>>end;
    for(int i=0;i<MAX;i++){
        d[i]=INF;
    }
    queue<pair<int,int>> q;
    q.push({start,0});
    d[start]=0;
    while(!q.empty()){
        int cur = q.front().first;
        int cost = q.front().second;
        q.pop();
        if(cur==end){
            if(minVal==cost){
                cnt++;
            }
            else if(minVal>cost){
                minVal=cost;
                cnt=1;
            }
            continue;
        }
        if(d[cur]!=cost){
            continue;
        }
        if(cur+1<MAX){
            if(d[cur+1]>=cost+1){
                d[cur+1]=cost+1;
                q.push({cur+1,cost+1});
            }
        }
        if(cur-1>=0){
            if(d[cur-1]>=cost+1){
                d[cur-1]=cost+1;
                q.push({cur-1,cost+1});
            }
        }
        if(cur*2<MAX){
            if(d[cur*2]>=cost+1){
                d[cur*2]=cost+1;
                q.push({cur*2,cost+1});
            }
        }
    }
    cout<<minVal<<"\n"<<cnt;
}