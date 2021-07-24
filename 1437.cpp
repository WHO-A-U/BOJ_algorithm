#include<iostream>
#include<cmath>
#include<algorithm>
#define MOD 10007
using namespace std;
int main(){
    int n;
    cin>>n;
    long long ans = 1;
    while(n>=5){
            ans = (ans*3)%MOD; 
            n-=3;
    }
    ans = (ans*n)%MOD;
    cout<<ans;
    return 0;
}