#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    queue<int> q;
    stack<int> s;
    vector<char> ans;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        q.push(x);
    }
    for(int i=1;i<=n;i++){
        s.push(i);
        ans.push_back('+');
        while(!s.empty()&&s.top()==q.front()){
            s.pop();
            q.front();
            q.pop();
            ans.push_back('-');
        }
    }
    if(!q.empty()){
        cout<<"NO";
    }
    else{
        for(char x : ans){
            cout<<x<<"\n";
        }
    }
    
}