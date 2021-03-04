#include<iostream>
#include<cstring>
using namespace std;
int main(){
    string s;
    while(1){
        cin>>s;
        bool f = true;
        if(s=="0")break;
        int l = s.length();
        for(int i=0;i<l/2;i++){
            if(s[i]!=s[l-1-i]){
                f=false;
                break;
            }
        }
        if(f){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }
    }
}