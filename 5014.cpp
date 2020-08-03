#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int dist[1000001];
bool visit[1000001];
int main(){
    int f,s,g,b[2];
    cin>>f>>s>>g>>b[0]>>b[1];
    b[1]=-b[1];
    for(int i=1;i<=f;i++)
        dist[i]=0x3f3f3f3f;
    queue<int> q;
    q.push(s);
    dist[s]=0;
    visit[s]=true;
    while(!q.empty()){
        int curfloor=q.front();
        int curdist=dist[curfloor];
        q.pop();
        for(int i=0;i<2;i++){
            int nextfloor=curfloor+b[i];
            if(nextfloor<=f&&nextfloor>=1&&dist[nextfloor]>curdist+1&&!visit[nextfloor]){
                q.push(nextfloor);
                visit[nextfloor]=true;
                dist[nextfloor]=curdist+1;
            }
        }
    }
    if(dist[g]==0x3f3f3f3f)
        cout<<"use the stairs";
    else
        cout<<dist[g];
}