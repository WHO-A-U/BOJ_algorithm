#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
map<string ,int> m1;
map<int,string> m2;
int Stoi(string str){
    int tmp=0;
    for(int i=0;i<str.length();i++){
        tmp*=10;
        tmp+=(str[i]-'0');
    }
    return tmp;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        m1[s]=i;
        m2[i]=s;
    }
    for(int i=0;i<m;i++){
        cin>>s;
        if(s[0]>='0'&&s[0]<='9'){
            cout<<m2[Stoi(s)]<<'\n';
        }else{
            cout<<m1[s]<<'\n';
        }
    }
}