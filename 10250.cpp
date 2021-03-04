#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int h,w,n;
        cin>>h>>w>>n;
        int XX = (n-1)/h+1;
        int YY =  (n-1)%h+1;
        cout<<YY;
        if(XX<10){
            cout<<"0"<<XX;
        }else{
            cout<<XX;
        }
        cout<<"\n";
    }
}