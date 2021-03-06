#include<iostream>
#include<queue>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    vector<int> ans;
    priority_queue<int,vector<int>> pqM;
    priority_queue<int,vector<int> , greater<int> > pqP;
    cin>>n;
    while(n--){
        cin>>x;
        if(x==0){
            if(pqP.empty()&&pqM.empty()){
                ans.push_back(0);
            }else if(pqP.empty()){
                ans.push_back(pqM.top());
                pqM.pop();
            }else if(pqM.empty()){
                ans.push_back(pqP.top());
                pqP.pop();
            }else{
                if(pqP.top()<abs(pqM.top())){
                    ans.push_back(pqP.top());
                    pqP.pop();
                }else{
                    ans.push_back(pqM.top());
                    pqM.pop();
                }
            }
        }else{
            if(x>0){
                pqP.push(x);
            }else{
                pqM.push(x);
            }
        }
    }
    for(int z: ans){
        cout<<z<<"\n";
    }
}