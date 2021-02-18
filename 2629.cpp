#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
vector<int> choo;
int v[31][40001];
int main(){
    int n,x,t;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        choo.push_back(x);
    }
    memset(v,false,sizeof(v));
    queue<pair<int,int> > q;
    q.push(make_pair(0,0));
    while(!q.empty()){
        int cur = q.front().first;
        int idx = q.front().second;
        q.pop();
        if(idx>=n){
            continue;
        }
        int plus = abs(cur+choo[idx]);
        int minus = abs(cur-choo[idx]);
        int absVal =abs(cur);
        if(!v[idx][absVal]){
            v[idx][absVal]=true;
            q.push(make_pair(cur,idx+1));
        }
        if(!v[idx][plus]){
            v[idx][plus]=true;
            q.push(make_pair(cur+choo[idx],idx+1));
        }
        if(!v[idx][minus]){
            v[idx][minus]=true;
            q.push(make_pair(cur-choo[idx],idx+1));
        }
    }
    
    
    cin>>t;
    while(t--){
        cin>>x;
        cout<<(v[n-1][x]?"Y ":"N ");
    }
}