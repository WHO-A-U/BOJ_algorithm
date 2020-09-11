#include<iostream>
#include<vector>
using namespace std;
vector<int> A;
bool visit[10];
void go(int end,int rest){
    if(rest==0){
        for(int i=0;i<A.size();i++)
            cout<<A[i]<<" ";
        cout<<'\n';
        return ;
    }
    for(int i=1;i<=end;i++)
        if(!visit[i]){
            A.push_back(i);
            visit[i]=true;
            go(end,rest-1);
            A.pop_back();
            visit[i]=false;
        }
    return ;
}
int main(){
    int n,m;
    cin>>n>>m;
    go(n,m);
}