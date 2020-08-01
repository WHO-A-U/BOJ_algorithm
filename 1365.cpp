#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> d(n);
    vector<int> len;
    for(int i=0;i<n;i++)
        cin>>d[i];
    len.push_back(d[0]);
    for(int i=1;i<n;i++)
    {
        auto p =lower_bound(len.begin(),len.end(),d[i]);
        if(p==len.end()){
            len.push_back(d[i]);
        }
        else{
            *p=d[i];
        }
    }
    cout<<n-len.size();
}