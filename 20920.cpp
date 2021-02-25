#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
vector<pair<int,string> > v;
struct cmp
{
    inline bool operator() (const pair<int,string> &a, const pair<int,string> &b)
    {
        if(a.first>b.first){
            return true;
        }
        if(a.first<b.first){
            return false;
        }
        if(a.second.length()>b.second.length()){
            return true;
        }
        if(a.second.length()<b.second.length()){
            return false;
        }
        if(a.second<b.second){
            return true;
        }
        return false;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    string s;
    cin>>n>>m;
    map<string,int> dict;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s.length()>=m)
            dict[s]++;
    }   
    map<string,int>::iterator it;
    for(it = dict.begin();it!=dict.end();it++){
        v.push_back(make_pair(it->second,it->first));
    }
    sort(v.begin(),v.end(),cmp());
    for(int i=0;i<v.size();i++){
        cout<<v[i].second<<"\n";
    }
}