#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int d[50001];
int main(){
    int n;
    cin>>n;
    vector<int> t;
    for(int i=0;i<=n;i++){
        d[i]=INF;
    }
    for(int i=1;i*i<=n;i++){
        d[i*i]=1;
        t.push_back(i*i);
    }
    for(int i=1;i<=n;i++){
        if(d[i]==1)continue;
        for(int x:t){
            if(i-x>0){
                d[i]=min(d[i],d[i-x]+1);
            }
        }
    }
    cout<<d[n];
}