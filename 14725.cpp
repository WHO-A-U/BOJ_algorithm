#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<iostream>
#include<deque>
using namespace std;
using vs = vector<string>;
using vvs = vector<vs>;
using ds = deque<string>;
using dds = deque<ds>;
void print(string a,int b){
    while(b--){
        cout<<"--";
    }
    cout<<a<<"\n";
}
void go(dds &ant,int depth){
    if(ant.empty()){
        return ;
    }
    sort(ant.begin(),ant.end());


    string cur = ant[0][0];
    dds tmp;

    for(int i=0;i<ant.size();i++){
        if(cur==ant[i][0]){
            ant[i].pop_front();
            if(!ant[i].empty())
                tmp.push_back(ant[i]);
        }
        else{
            print(cur,depth);
            go(tmp,depth+1);
            tmp.clear();
            cur=ant[i][0];
            ant[i].pop_front();
            if(!ant[i].empty())
                tmp.push_back(ant[i]);
        }
    }
    print(cur,depth);
    if(!tmp.empty()){
        go(tmp,depth+1);
    }
}
int main(){
    int n,m;
    string s;
    cin>>n;
    dds ant;
    for(int i=0;i<n;i++){
        cin>>m;
        ds v(m);
        for(int j=0;j<m;j++){
            cin>>v[j];
        }
        ant.push_back(v);
    }
    go(ant,0);

}