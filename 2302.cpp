#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long d[41][2];
int main(){
    int n,m,x,ans=1;
    cin>>n>>m;
    vector<int> p;
    p.push_back(0);
    for(int i=0;i<m;i++){
        cin>>x;
        p.push_back(x);
    }
    p.push_back(n+1);
    for(int i=1;i<=40;i++){
        d[i][0] = d[i-1][1]+1;//자기 포함
        d[i][1] = d[i-1][0]+d[i-1][1];       //자기 포함하지 않을때
    }
    for(int i=1;i<p.size();i++){
        int diff = p[i]-p[i-1]-2;
        if(diff>=0)
            ans*=(d[diff][0]+d[diff][1]+1);
    }
    cout<<ans;

}