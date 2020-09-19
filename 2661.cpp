#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
bool flag=false;
string ans;
void go(string s,int n){
    if(n==0){
        ans=s;
        flag=true;
        return ;
    }
    for(int i=1;i<=3;i++){
        string tmp=s+to_string(i);
        bool f=true;
        for(int j=1;j<=tmp.length()/2;j++){
            if(tmp.substr(tmp.length()-j)==tmp.substr(tmp.length()-(2*j),j)){
                f=false;
                break;
            }
        }
        if(f){
            go(tmp,n-1);
            if(flag)
                return ;
        }
    }
}
int main(){
    int n;
    cin>>n;
    go("",n);
    cout<<ans;
}