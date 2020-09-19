#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin>>str;
    char a = str[0];
    int ans[2]={0,0};
    if(a=='0')ans[0]++;
    else ans[1]++;
    for(int i=0;i<str.length();i++){
        if(a!=str[i]){
            a=str[i];
            if(a=='0')ans[0]++;
            else ans[1]++;
        }
    }
    cout<<min(ans[0],ans[1]);
}