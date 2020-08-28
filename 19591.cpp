#include<iostream>
#include<deque>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
vector<ll> num;
vector<char> oper;
void parsing(string s){
    ll tmp=0;
    bool flag=false;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            tmp*=10;
            tmp+=(s[i]-'0');
        }
        else{
            if(i==0){
                flag=true;
                continue;
            }
            oper.push_back(s[i]);
            num.push_back(tmp);
            tmp=0;
        }
    }
    num.push_back(tmp);
    if(flag){
        num[0]=-num[0];
    }
}
ll eval(ll a,ll b,char s){
    if(s=='+')return a+b;
    if(s=='-')return a-b;
    if(s=='*')return a*b;
    if(s=='/')return a/b;
}
int getPriorty(char s){
    if(s=='+'||s=='-')return 1;
    return 2;
}
ll calculate(){
    int i=0,j=num.size()-1;
    if(j==0)
        return num[0];
    while(j-i>1){
    // cout<<endl;
    // for(int k=0;k<num.size();k++){
    //     cout<<num[k]<<" ";
    // }
    // cout<<endl;
    // for(int k=0;k<oper.size();k++){
    //     cout<<oper[k]<<" ";
    // }
    // cout<<endl;
        int a = getPriorty(oper[i]);
        int b = getPriorty(oper[j-1]);
        if(a>b){
            num[i+1]=eval(num[i],num[i+1],oper[i]);
            i++;
        }else if(a<b){
            num[j-1]=eval(num[j-1],num[j],oper[j-1]);
            j--;
        }else{
            ll front=eval(num[i],num[i+1],oper[i]);
            ll back = eval(num[j-1],num[j],oper[j-1]);
            if(front>=back){
                num[i+1]=front;
                i++;
            }else{
                num[j-1]=back;
                j--;
            }
        }
    }
    return eval(num[i],num[j],oper[i]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    parsing(s);
    // while(num.size()>0){
    //     cout<<num.front()<<" ";
    //     num.pop_front();
    // }
    // while(oper.size()>0){
    //     cout<<oper.front()<<" ";
    //     oper.pop_front();
    // }
    cout<<calculate();
}