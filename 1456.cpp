#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,maxVal=0;
    cin>>n;
    vector<int> p(n,0);
    for(int i=0;i<n;i++){
        cin>>p[i];
        maxVal=max(maxVal,p[i]);
    }
    vector<double> a(n,0.0);
    for(int i=0;i<n;i++){
        a[i]=((double)p[i]/(double)maxVal)*100.0;
    }
    double sum=0.0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    cout<<sum/n;
    
}

