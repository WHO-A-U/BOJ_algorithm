#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int n,k;
void go(int cur,int cnt){
    if(cur>n||cnt==0){
        if(v.size()==k){
            for(int x : v){
                cout<<x<<" ";
            }
            cout<<"\n";
        }
        return ;
    }
    for(int i=cur;i<=n;i++){
        v.push_back(i);
        go(i,cnt-1);
        v.pop_back();
    }
    return ;
}
int main(){
    cin>>n>>k;
    go(1,k);
}