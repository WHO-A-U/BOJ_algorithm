#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
vector<int> node[51];
bool alive[51];
int ans=0;
int go(int cur){
    if(!alive[cur])
        return 0;
    if(node[cur].size()==0)
        return 1;
    int cnt=0;
    for(int i=0;i<node[cur].size();i++){
        cnt+=go(node[cur][i]);
    }
    if(cnt==0)
        return 1;
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,root;
    cin>>n;
    memset(alive,true,sizeof(alive));
    for(int i=0;i<n;i++){
        cin>>x;
        if(x!=-1){
            node[x].push_back(i);
        }else{
            root=i;
        }
    }
    int dead;
    cin>>dead;
    alive[dead]=false;
    cout<<go(root);
}