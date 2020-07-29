#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
vector<long long> A,B;
vector<long long> B2;
map<long long ,long long> A2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long t,n,m,x;
    cin>>t>>n;
    A.push_back(0);
    B.push_back(0);
    for(int i=0;i<n;i++){
        cin>>x;
        A.push_back(x);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x;
        B.push_back(x);
    }
    for(int i=1;i<A.size();i++){
        A[i]+=A[i-1];
    }
    for(int i=1;i<B.size();i++){
        B[i]+=B[i-1];
    }
   for(int i=1;i<A.size();i++){
       for(int j=0;j<i;j++){
        //    A2.push_back(A[i]-A[j]);
        if(A2.find(A[i]-A[j])==A2.end()){
            A2[A[i]-A[j]]=1;
        }
        else{
            A2[A[i]-A[j]]++;
        }
       }
   }
   for(int i=1;i<B.size();i++){
       for(int j=0;j<i;j++){
           B2.push_back(B[i]-B[j]);
       }
   }
   sort(B2.begin(),B2.end());
    long long ans=0;
    for(int i=0;i<B2.size();i++){
        if(A2.find(t-B2[i])!=A2.end()){
            ans+=A2[t-B2[i]];
        }
    }
    cout<<ans;
}