#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> num,oper;
int d[4]; // + - x /
int minVal , maxVal;
int cal(int a , int b,int op){
    if(op==0)return a+b;
    if(op==1)return a-b;
    if(op==2)return a*b;
    if(op==3)return a/b;
}
void go(int idx,int ret){
    if(idx>=num.size()){
        minVal=min(minVal , ret);
        maxVal=max(maxVal ,ret);
        return ;
    }
    for(int i=0;i<4;i++){
        if(d[i]>0){
            d[i]--;
            go(idx+1,cal(ret,num[idx],i));
            d[i]++;
        }
    }
}
int main(){
    minVal=0x3f3f3f3f;
    maxVal = -minVal;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        num.push_back(x);
    }
    for(int i=0;i<4;i++){
        cin>>d[i];
    }
    go(1,num[0]);
    cout<<maxVal<<"\n"<<minVal;
}