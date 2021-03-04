#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    int n,k;
    queue<int> q;
    vector<int> v;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    while(!q.empty()){
        int t =k-1;
        while(t--){
            q.push(q.front());
            q.pop();
        }
        v.push_back(q.front());
        q.pop();
    }
    cout<<"<"<<v[0];
    for(int i=1;i<v.size();i++){
        cout<<", "<<v[i];
    }
    cout<<">";

}
