#include<bits/stdc++.h>
using namespace std;
int d[30];
int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='a'&&s[i]<='z'){
            d[s[i]-'a']++;
        }else{
            d[s[i]-'A']++;
        }
    }
    int idx,maxVal=0;
    for(int i=0;i<'z'-'a'+1;i++){
        if(maxVal<d[i]){
            maxVal=d[i];
            idx=i;
        }
    }
    for(int i=0;i<'z'-'a'+1;i++){
        if(i!=idx&&maxVal==d[i]){
            cout<<"?";
            return 0;
        }
    }

    cout<<(char)('A'+idx);

}