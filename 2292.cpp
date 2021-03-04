#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;;i++){
        n-=(i==1?1:(i-1)*6);
        if(n<=0){
            cout<<i;
            break;
        }

    }
}