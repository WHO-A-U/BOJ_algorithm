#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
bool d[2001][2001];
int main(){
    int n;
    cin>>n;
    queue<pair<pair<int,int>,int>>q; //current,clipboard  / count
    q.push({{1,0},0});
    d[1][0]=true;
    while(!q.empty()){
        int cur = q.front().first.first;
        int clip = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        d[cur][clip]=true;
        if(cur==n){
            cout<<cnt;
            break;
        }
        if(cur+clip<=2000&&clip > 0 && !d[cur+clip][clip])
            q.push({{cur+clip,clip},cnt+1});
        if(!d[cur-1][clip]&&cur-1>=0&&cur-1<2001){
            q.push({{cur-1,clip},cnt+1});
            d[cur-1][clip]=true;
        }
        if(!d[cur][cur]){
            q.push({{cur,cur},cnt+1});
            d[cur][cur]=true;
        }
    }
}