#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    while(1){
        vector<int> a(3,0);
        for(int i=0;i<3;i++){
            cin>>a[i];
        }
        if(a[0]==0&&a[1]==0&&a[2]==0){
            break;
        }
        sort(a.begin(),a.end());
        if(a[2]*a[2]==a[1]*a[1]+a[0]*a[0]){
            cout<<"right\n";
        }else{
            cout<<"wrong\n";
        }
    }
}