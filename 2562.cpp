#include<bits/stdc++.h>
using namespace std;
int d[10];
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int n = a*b*c;
  while(n!=0){
      d[n%10]++;
      n/=10;
  }
  for(int i=0;i<10;i++){
      cout<<d[i]<<"\n";
  }
}

