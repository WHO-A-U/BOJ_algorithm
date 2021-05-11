#include <bits/stdc++.h>
using namespace std;
int foo(char a){
    int x = a,sum=0;
    while(x!=0){
        sum+=x%10;
        x/=10;
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        int n = foo(s[i]);
        while(n--){
            cout<<s[i];
        }
        cout<<"\n";
    }
}