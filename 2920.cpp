#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    vector<int> a;
    vector<int> b;
    for(int i=0;i<8;i++){
        cin>>n;
        a.push_back(n);
    }
    bool flag=true;
    for(int i=1;i<8;i++){
        if(a[i]<a[i-1]){
            flag=false;
            break;
        }
    }
    if(flag){
        cout<<"ascending";
        return 0;
    }

    flag=true;
    for(int i=1;i<8;i++){
        if(a[i]>a[i-1]){
            flag=false;
            break;
        }
    }
    if(flag){
        cout<<"descending";
    }else{
        cout<<"mixed";
    }
}

