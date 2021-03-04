#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n,x;
    cin>>n;
    stack<int> s;
    while(n--){
        cin>>x;
        if(x!=0){
            s.push(x);
        }else{
            if(!s.empty()){
                s.pop();
            }
        }
    }
    int ans=0;
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    cout<<ans;
}