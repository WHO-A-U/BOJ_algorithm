#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> se;
    int n;
    for(int i=0;i<10;i++){
        cin>>n;
        se.insert(n%42);
    }
    cout<<se.size();
}

