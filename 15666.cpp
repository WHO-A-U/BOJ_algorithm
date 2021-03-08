#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,k,x;
vector<int> v;
vector<int> num;
bool visit[10];
void go(int idx , int cnt){
    if(idx>=num.size()||cnt==0){
        if(v.size()==k){
            for(int x : v){
                cout<<x<<" ";
            }
            cout<<"\n";
        }
        return ;
    }

    for(int i=idx;i<num.size();i++){
            v.push_back(num[i]);
            go(i,cnt-1);
            v.pop_back();
    }
    return ;
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x;
        num.push_back(x);
    }
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    go(0,k);
}