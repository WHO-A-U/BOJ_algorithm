#include<iostream>
#include<stack>
#include<cstring>
#include<string>
using namespace std;
int main(){
    string s;
    while(1){
        stack<char> st;
        getline(cin,s);
        if(s==".")
            break;
        int a=0,b=0;
        bool flag=true;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]==')'||s[i]=='['||s[i]==']'){
                st.push(s[i]);
            }
            while(st.size()>=2){
                char ft = st.top();
                st.pop();
                char se = st.top();
                if((se=='('&&ft==')')||(se=='['&&ft==']')){
                    st.pop();
                }else{
                    st.push(ft);
                    break;
                }
            }
        }
        if(st.empty()){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }
    }
}