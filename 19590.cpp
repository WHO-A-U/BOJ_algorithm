#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int> bullet;
int main(){
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        bullet.push_back(x);
    }
    sort(bullet.begin(),bullet.end());
    int cur =bullet[n-1];
    for(int i=n-2;i>=0;i--){
        int curcnt=cur-bullet[i];
        cur=abs(curcnt);
    }
    cout<<cur;
}