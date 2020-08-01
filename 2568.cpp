#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
bool comp (pair<int,int> &a,pair<int,int> &b){
    if(a.first<b.first)
        return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b;
    cin>>n;
    vector<pair<int,int>> d(n);
    vector<pair<int,int>> path(n);
    vector<int> len;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        d[i]={a,b};
    }   
    if(n==1){
        cout<<0;
        return 0;
    }
    sort(d.begin(),d.end(),comp);

    len.push_back(d[0].second);
    path[0]={d[0].first,1};
    int maxidx=0;
    for(int i=1;i<n;i++){
        auto p = lower_bound(len.begin(),len.end(),d[i].second);
        if(p==len.end()){
            len.push_back(d[i].second);
            path[i]={d[i].first,len.size()};
        }
        else{
            *p=d[i].second;
            path[i]={d[i].first,p-len.begin()+1};
        }
        maxidx=max(maxidx,path[i].second);
    }
    // for(int i=0;i<n;i++){
    //      printf("%d's   a number  : %d/ b number : %d / path : %d\n",i,path[i].first,d[i].second,path[i].second);
    // }
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        if(maxidx!=path[i].second){
            s.push({path[i].first});
        }
        else
            maxidx--;
    }
    cout<<s.size()<<'\n';
    while(!s.empty()){
        cout<<s.top()<<'\n';
        s.pop();
    }
}