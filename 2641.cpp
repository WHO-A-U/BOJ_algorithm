#include<bits/stdc++.h>
using namespace std;

int rev[]={0,3,4,1,2};
vector<int> revTarget ;
bool cmp(vector<int> target,vector<int> cur){
    int n = cur.size();
    for(int i=0;i<cur.size();i++){
        int idx = i;
        bool flag1=true,flag2=true;
        for(int j=0;j<target.size();j++){
            if(target[j]!=cur[(idx+j)%n]){
                flag1=false;
            }
            if(revTarget[j]!=cur[(idx+j)%n]){
                flag2=false;
            }
            if(!flag1&&!flag2)
                break;
        }
        if(flag1||flag2)
            return true;
    }
    return false;
}

int main(){
    int n,m;
    cin>>n;
    vector<vector<int>> ans;
    vector<int> target(n,0);
    for(int i=0;i<n;i++){
        cin>>target[i];
    }
    revTarget = target;
    reverse(revTarget.begin(),revTarget.end());
    for(int i=0;i<revTarget.size();i++){
        revTarget[i]=rev[revTarget[i]];
    }
    cin>>m;

    while(m--){
        vector<int> tmp(n,0);
        for(int i=0;i<n;i++){
            cin>>tmp[i];
        }
        if(cmp(target,tmp)){
            ans.push_back(tmp);
        }
    }

    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}