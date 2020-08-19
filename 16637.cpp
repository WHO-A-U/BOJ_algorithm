#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;
int n,ans=-0x7fffffff;
string s;
// 9
// 3+8*7-9*2
// 7
// 8*3+5+2
vector<int> bracket;
int operation (int opnd1,char s,int open2){
    if(s=='+')return opnd1+open2;
    if(s=='-')return opnd1-open2;
    if(s=='*')return opnd1*open2;
}
int eval(int idx1,int idx2){
    int tmp=0;
    char oper='+';
    for(;idx1<=idx2;idx1++){
        if(s[idx1]>='0'&&s[idx1]<='9'){
            tmp=operation(tmp,oper,s[idx1]-'0');
        }
        else{
            oper=s[idx1];
        }
    }
    return tmp;
}
void cal(){
    int tmp=0;
    int idx=0;
    char oper ='+';
    for(int i=0;i<s.length();i++){
        if(bracket.size()>idx&&bracket[idx]==i){
            tmp=operation(tmp,oper,eval(bracket[idx],bracket[idx+1]));
            i=bracket[idx+1];
            idx+=2;
        }
        else{
            if(s[i]>='0'&&s[i]<='9'){
                tmp=operation(tmp,oper,s[i]-'0');
            }   
            else{
                oper=s[i];
            }      
        }
    }
    ans = max(ans,tmp);
    return ;
}
void go(int idx){
    if(idx>=s.length()){
        cal();
        return ;
    }
    if(idx+2<s.length()){
        bracket.push_back(idx);
        bracket.push_back(idx+2);
        go(idx+4);
        bracket.pop_back();
        bracket.pop_back();
    }
    go(idx+2);
}
int main(){
    cin>>n;
    cin>>s;
    go(0);//start at index 0 and / 0 means '('     1 means')';
    cout<<ans;
}