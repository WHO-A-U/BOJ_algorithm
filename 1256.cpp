#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#define MAX 1000000001
using namespace std;
using ll = long long;
long long d[201][201];
int comb(int n,int m){
    if(d[n][m]>0)return d[n][m];
    if(n==m||m==0){
        return d[n][m]=1;
    }
    d[n][m]=comb(n-1,m)+comb(n-1,m-1);
    return d[n][m]=d[n][m]>=MAX?MAX:d[n][m];
}
string go(int n,int m,int k){
    if(comb(n+m,n)<=k){
        return "-1";
    }
    long long mid = comb(n+m-1,n-1);
    if(n==1||m==1){
        string ret="";
        vector<char> va(n,'a');
        vector<char> vz(m,'z');
        va.insert(va.end(),vz.begin(),vz.end());
        do{
            if(k==0){
                break;
            }
            k--;
        }while(next_permutation(va.begin(),va.end()));
        for(int i=0;i<va.size();i++){
            ret+=va[i];
        }
        return ret;
    }
    if(k>=mid){
        return "z"+go(n,m-1,k-mid);
    }else{
        return "a"+go(n-1,m,k);
    }

}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    cout<<go(n,m,k-1);
}