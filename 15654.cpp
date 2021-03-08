#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
vector<int> num;
bool visit[10];
int n,k;
void go(int cnt){
    if(cnt==0){
        if(v.size()==k){
            for(int x : v){
                cout<<x<<" ";
            }
            cout<<"\n";
        }
        return ;
    }
    for(int i=0;i<n;i++){
        if(!visit[i]){
            visit[i]=true;
            v.push_back(num[i]);
            go(cnt-1);
            v.pop_back();
            visit[i]=false;
        }
    }
    return ;
}
int main(){
    int x;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x;
        num.push_back(x);
    }
    sort(num.begin(),num.end());
    go(k);
}