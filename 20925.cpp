#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int d[2002][201];
vector<int> e[201];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t,a,b;
    cin>>n>>t;
    vector<int> entry(n,0);
    vector<int> exp(n,0);
    vector<int> start;
    for(int i=0;i<n;i++){
        cin>>entry[i]>>exp[i];
        if(entry[i]==0){
            start.push_back(i);
        }
    }
    for(int i=0;i<n;i++){
        e[i].assign(n,0);
        for(int j=0;j<n;j++){
            cin>>e[i][j];
        }
    }
    for(int i=0;i<=t;i++){
        for(int j=0;j<n;j++){
            d[i][j]=-1;
        }
    }
    queue<pair<int,int> >q; //시간 , 지역
    for(int i=0;i<start.size();i++){
        q.push(make_pair(0,start[i]));
        d[0][start[i]]=0;
    }
    while(!q.empty()){
        int curTime = q.front().first;
        int area = q.front().second;
        int curExp = d[curTime][area];
        q.pop();
        if(curTime+1<=t && d[curTime+1][area]<curExp+exp[area]){
            d[curTime+1][area]=curExp+exp[area];
            q.push(make_pair(curTime+1,area));
        }
        for(int i=0;i<n;i++){
            if(i==area)continue;
            int cost = e[area][i];
            if(curTime+cost<=t&&curExp>=entry[i]&&d[curTime+cost][i] < curExp){
                d[curTime+cost][i] = curExp;
                q.push(make_pair(curTime+cost,i));
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans = max(ans , d[t][i]);
    }
    cout<<ans;
    return 0;
}