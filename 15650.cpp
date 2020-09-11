#include<iostream>
#include<vector>
using namespace std;
vector<int> A;
bool visit[10];
void go(int cur ,int end,int rest){
    if(rest==0){
        for(int i=0;i<A.size();i++)
            cout<<A[i]<<" ";
        cout<<'\n';
        return ;
    }
    if(cur>end)
        return ;
    A.push_back(cur);
    go(cur+1,end,rest-1);
    A.pop_back();
    go(cur+1,end,rest);
    return ;
}
int main(){
    int n,m;
    cin>>n>>m;
    go(1,n,m);
}