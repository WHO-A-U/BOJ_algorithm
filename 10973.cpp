#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    do{
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }while(next_permutation(a.begin(),a.end()));

}