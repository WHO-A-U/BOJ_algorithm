#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    long long n,b,c;
    cin>>n;
    vector<long long> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cin>>b>>c;
    long long ans=0;
    for(int i=0;i<n;i++){
        if(b>=A[i])
            ans+=1;
        else{
            ans+=ceil((double)(A[i]-b)/(double)c)+1;//총감독관 한명 나머지 부감독관
        }
    }
    cout<<ans;
}