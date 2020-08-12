#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define INF 0x3f3f3f3f3f3f
#define ll long long
using namespace std;
vector<int> num;
vector<int> oper;
int n,x,adds,subs,muls,divs;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        num.push_back(x);
    }   
    cin>>adds>>subs>>muls>>divs;
    while(adds--)oper.push_back(0);
    while(subs--)oper.push_back(1);
    while(muls--)oper.push_back(2);
    while(divs--)oper.push_back(3);
    ll minval=INF,maxval=-INF;
    do{
        ll t=num[0];
        for(int i=1;i<n;i++){
            if(oper[i-1]==0)t+=num[i];
            if(oper[i-1]==1)t-=num[i];
            if(oper[i-1]==2)t*=num[i];
            if(oper[i-1]==3)t/=num[i];
        }
        minval=min(minval,t);
        maxval=max(maxval,t);
    }while(next_permutation(oper.begin(),oper.end()));
    cout<<maxval<<'\n'<<minval;
}