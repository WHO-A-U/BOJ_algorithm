#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> d(n);
    vector<int> path(n);
    vector<int> len;
    // len.push_back(-1000000001);
    int tmp=0;
    cin>>d[0];
    if(n==1){
        cout<<"1\n"<<d[0];
        return 0;
    }
    path[0]=1;
    len.push_back(d[0]);
    for(int i=1;i<n;i++){
        cin>>d[i];
        auto iter=lower_bound(len.begin(),len.end(),d[i]);
        if(iter == len.end()&&len.back()<d[i]){
            // cout<<"!";
            len.push_back(d[i]);
            path[i]=(len.size());
        }
        else{
            *iter=d[i];
            path[i]=(iter-len.begin()+1);
        }
        if(path[i]>tmp){
            tmp=path[i];
        }   
    }
    // cout<<len.size();
    // for(int i=0;i<n;i++){
    //     printf("%d's  number  : %d / path : %d\n",i,d[i],path[i]);
    // }
    stack <int> s;
    for(int i=n-1;i>=0;i--){
        if(path[i]==tmp){
            s.push(d[i]);
            tmp--;
        }
    }
    cout<<s.size()<<'\n';
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    
}