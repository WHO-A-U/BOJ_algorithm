#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int d[21][21];
vector<int> v;
int n;
int total=0;
int ans=0x3f3f3f3f;
int cal(){
    int team1=0;
    int team2=0;
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            team2+=(d[v[i]][v[j]]+d[v[j]][v[i]]);
        }
    }
    vector<int> t;
    int idx=0;
    for(int i=0;i<n;i++){
        if(v[idx]==i){
            idx++;
        }
        else{
            t.push_back(i);
        }
    }
    for(int i=0;i<t.size();i++){
        for(int j=i+1;j<t.size();j++){
            team1+=(d[t[i]][t[j]]+d[t[j]][t[i]]);
        }
    }
    return abs(team1-team2);
}
void go(int x){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(v.size()==n/2){
        ans=min(ans,cal());
        return ;
    }
    if(x==n)
        return ;
    v.push_back(x);
    go(x+1);
    v.pop_back();
    go(x+1);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];
            total+=d[i][j];
        }
    }
    go(0);
    cout<<ans;
}