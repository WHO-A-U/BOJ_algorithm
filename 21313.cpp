#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n/2;i++){
        cout<<"1 2 ";
    }
    if(n%2){
        cout<<"3";
    }
}