#include<bits/stdc++.h>
using namespace std;
int main(){
  int n=0,a,idx;
  for(int i=1;i<=9;i++){
      cin>>a;
      if(n<a){
          n=a;
          idx=i;
      }
  }
  cout<<n<<"\n"<<idx;
}

