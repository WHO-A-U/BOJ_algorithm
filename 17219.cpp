#include<iostream>
#include<cstring>
#include<map>
using namespace std;
map<string,string> dic;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    string s,id;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s;
        cin>>id;
        dic[s]=id;
    }
    for(int i=0;i<m;i++){
        cin>>s;
        cout<<dic[s]<<"\n";
    }
}