#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

string s,pattern;
vector<int> getLPS(const string &s){
    int len = s.length();
    vector<int> lps(len,0);
    int j=0,i=1;
    while(j+i<len){
        if(s[j+i]==s[j]){
            j++;
            lps[i+j-1]=j;
        }else{
            if(j==0){
                i++;
            }else{
                i += j - lps[j-1];
                j = lps[j-1];
            }
        }
    }
    return lps;
}
vector<int> getKMP(const string &s ,const string  &pattern){
    int slen = s.length();
    int plen = pattern.length();

    vector<int> ans;
    vector<int> lps = getLPS(pattern);

    int matched = 0;

    for(int i=0;i<slen;i++){
        while(matched>0 && s[i]!=pattern[matched]){
            matched = lps[matched-1];
        }
        if(s[i] == pattern[matched]){
            matched++;
            if(matched==plen){
                ans.push_back(i-plen+2);
                matched = lps[matched-1];
            }
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    getline(cin,s);
    getline(cin,pattern);
    vector<int> ans = getKMP(s,pattern);
    cout<<ans.size()<<"\n";
    for(int x: ans){
        cout<<x<<" ";
    }
}