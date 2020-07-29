#include<iostream>
using namespace std;
long long D[20001];
int main(){
    int T;
    cin >>T;
    D[1]=1;
    for(int i=1;i<=T;i++){
        D[i+1]=D[i]*(i+1);
        while(1){
            if(D[i+1]%10==0){
                D[i+1]/=10;
            }
            else{
                D[i+1]%=1000000000;
                break;
            }
        }
    }
    // for(int i=1;i<=T;i++)
    // {
    cout<<D[T]%10<<"\n";
    // }
}