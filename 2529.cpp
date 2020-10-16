#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int> tmp;
bool v[10];
char oper[10];
long long  maxVal=0,minVal=0x3f3f3f3f3f3f;
int n;
void go(int idx){
  if(idx==n+1){
    long long num =0;
    for(int i=0;i<tmp.size();i++)
        num = num * 10 + tmp[i];
    maxVal = max(maxVal,num);
    minVal = min(minVal,num);
    return ;    
  }
  for(int i=0;i<10;i++){
    if(!v[i]){
        bool flag=false;
        if(idx>=1){
            if(oper[idx-1]=='<'){
                if(tmp.back()<i)flag=true;
            }
            else{
                if(tmp.back()>i)flag=true;
            }
        }else{
            flag=true;
        }
        if(flag){
            v[i]=true;
            tmp.push_back(i);
            go(idx+1);
            v[i]=false;
            tmp.pop_back();
        }
    }
  }
  return ;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>oper[i];
    }
    go(0);// start integer at index 0;
    if(maxVal<pow(10.0,n))
        cout<<"0"<<maxVal;
    else
        cout<<maxVal;
    cout<<"\n";
    if(minVal<pow(10.0,n))
        cout<<"0"<<minVal;
    else
        cout<<minVal;
}