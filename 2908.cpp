#include<bits/stdc++.h>
using namespace std;
int rev(int n){
    int sum=0;
    while(n!=0){
        sum*=10;
        sum+=(n%10);
        n/=10;
    }
    return sum;
}
int main(){
  int a,b;
  cin>>a>>b;
  if(rev(a)>rev(b)){
      cout<<rev(a);
  }else{
      cout<<rev(b);
  }
}

