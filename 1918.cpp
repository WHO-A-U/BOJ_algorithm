#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string go(string s){
    if(s.length()==1){
        return s;
    }
    int idx,tmp=-1;
    int sum=0;
    if(s[0]=='('){
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')sum++;
            if(s[i]==')')sum--;
            if(sum==0){
                idx=i+1;
                if(idx==s.length()){
                    return go(s.substr(1,s.length()-2));
                }else{
                    break;
                }
            }
        }
    }
    
    sum=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(')sum++;
        if(s[i]==')')sum--;
        if(sum==0&& (s[i]=='+'||s[i]=='-'))tmp=i;
        if(sum==0&&(s[i]=='/'||s[i]=='*'))idx=i;
    }

    if(tmp!=-1){
        idx=tmp;
    }

    return go(s.substr(0,idx))+go(s.substr(idx+1,101))+s[idx];
}
int main(){
    string s;
    cin>>s;
    cout<<go(s);
}