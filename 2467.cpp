#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ans=0x3f3f3f3f3f,n,x;
    cin>>n;
    vector<long long> d(n);    

    for(int i=0;i<n;i++){
        cin>>d[i];
    }

    int i=0,j=n-1,idx1,idx2,sum;
    while(i<j){
        sum = abs(d[i]+d[j]);
        if(ans>sum){
            ans = sum;
            idx1=i;
            idx2=j;
        }

        if(abs(d[i+1]+d[j]) > abs(d[i]+d[j-1]))
            j--;
        else
            i++;
        
    }
    cout<<d[idx1]<<" "<<d[idx2];
    
}