#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
vector<pair<int,int>> v;
int n,m,minval=0x3f3f3f3f;
int d[101][10101];
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
    d[0][cost[0]]=memory[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<10001;j++){
            if(j-cost[i]>=0){
                d[i][j]=max(d[i][j],d[i-1][j-cost[i]]+memory[i]);
            }
            d[i][j]=max(d[i][j],d[i-1][j]);
            if(d[i][j]>=m){
                minval=min(minval,j);
            }
        }
    }
    cout<<minval;
}