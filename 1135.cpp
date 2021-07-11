#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,x;
vector<int> childs[51];
int go(int idx){

    vector<int> tmp;

    for(int i=0;i<childs[idx].size();i++){
        tmp.push_back(go(childs[idx][i]));
    }
    
    sort(tmp.begin(),tmp.end());
    reverse(tmp.begin(),tmp.end());
    
    int need = tmp.size();
    
    for(int i=0;i<tmp.size();i++){
        need = max(need , i + 1 + tmp[i]);
    }

    return need;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        if( x != -1)
            childs[x].push_back(i);
    }
    
    cout<<go(0);
}
