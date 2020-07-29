#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
int main()
{
    map<string,int> m;
    int a,b;
    cin>>a>>b;
    while(a--)
    {
        string name;
        cin>>name;
        m[name]|=1;
    }
    while(b--)
    {
        string name;
        cin>>name;
        m[name]|=2;
    }
    vector<string> ans;
    for(auto &p :m){
        if(p.second==3)
            ans.push_back(p.first);
    }
    cout<<ans.size()<<'\n';
    for(auto &name:ans){
        cout<<name<<'\n';
    }
}