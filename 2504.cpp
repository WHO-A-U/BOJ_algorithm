#include<iostream>
#include<cstring>
using namespace std;
string str;
bool flag=true;
int cal(string s){
    if(s.length() == 0)
        return 0;
    if(s.length()==2&&s[0]=='('&&s[1]==')')return 2;
    if(s.length()==2&&s[0]=='['&&s[1]==']')return 3;
    int cnt=0;
    if(s[0]=='('){
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')cnt++;
            if(s[i]==')')cnt--;
            if(cnt==0&&i!=s.length()-1){
             return cal(s.substr(0,i+1))+cal(s.substr(i+1)) ;  
            }
        }
        if(cnt!=0) flag=false;
        return 2*cal(s.substr(1,s.length()-2)); 
    }
    else if(s[0]=='['){
        for(int i=0;i<s.length();i++){
            if(s[i]=='[')cnt++;
            if(s[i]==']')cnt--;
            if(cnt==0&&i!=s.length()-1){
             return cal(s.substr(0,i+1))+cal(s.substr(i+1)) ;   
            }
        }
        if(cnt!=0)flag=false;
        return 3*cal(s.substr(1,s.length()-2));
    }
    flag=false;
    return -1;
}
int main(){
    cin>>str;
    int ans=cal(str);
    if(!flag){
        cout<<"0";
    }else{
        cout<<ans;
    }
}