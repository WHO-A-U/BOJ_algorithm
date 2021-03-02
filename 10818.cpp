#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,minA=0x3f3f3f3f,maxA=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        minA = min(minA , a);
        maxA = max(maxA , a);
    }
    cout<<minA<<" "<<maxA;
}

