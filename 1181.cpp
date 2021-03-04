#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp(string &a,  string &b){
    if(a.length()<b.length()){
        return true;
    }
    if(a.length()>b.length()){
        return false;
    }
    return a<b;
}
int main(){
    int n;
    cin>>n;
    string s;
    vector<string> v;
    for(int i=0;i<n;i++){
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),cmp);
    v.erase(unique(v.begin(),v.end()),v.end());
    for(auto x: v){
        cout<<x<<"\n";
    }
}