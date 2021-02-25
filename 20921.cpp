#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int l = 1,r = n,len;
    while(l<=r){
        len = r-l;
        if(len<=k){
            k-=len;
            cout<<r<<" ";
            r--;
        }else{
            cout<<l<<" ";
            l++;
        }
    }
    return 0;
}