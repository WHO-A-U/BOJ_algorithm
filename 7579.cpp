#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
using namespace std;
int n,m;
int d[10001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    vector<int> memory(n);
    vector<int> cost(n);
    for(int i=0;i<n;i++){
        cin>>memory[i];
    }
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    
    queue<pair<int,int>> q;
    map<int,int>::iterator it;
    q.push({0,0});
    for(int i=0;i<n;i++){
        map<int,int> dict;
        dict[0]=max(0,dict[0]);
        while(!q.empty()){
            int cur = q.front().first;
            int mem = q.front().second;
            q.pop();
            int next = cur+cost[i];
            int nextMem = mem+memory[i];
            if(dict.find(cur)==dict.end()){
                dict[cur]=mem;
            }else{
                if(dict[cur]<mem){
                    dict[cur] = mem;
                }
            }
            if(dict.find(next)==dict.end()){
                dict[next]=nextMem;
            }else{
                if(dict[next]<nextMem){
                    dict[next] = nextMem;
                }
            }
        }
        for(it = dict.begin();it!=dict.end();it++){
            if(d[it->first]<it->second){
                d[it->first]=it->second;
            }
            q.push({it->first,d[it->first]});
        }
        
    }
    for(int i=0;i<10001;i++){
        if(d[i]>=m){
            cout<<i;
            break;
        }
    }
}