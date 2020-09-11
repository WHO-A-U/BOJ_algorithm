#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
vector<int> numArr;
set<int> numSet;
map<int,int> Mapping;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,id=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        numArr.push_back(x);
        numSet.insert(x);
    }
    for( auto it = numSet.begin();it!=numSet.end();it++)
        Mapping[*it]=id++;
    for(int i=0;i<numArr.size();i++){
        cout<<Mapping[numArr[i]]<<" ";
    }
}