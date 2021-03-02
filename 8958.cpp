#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        cin>>s;
        int c=1,sum=0;
        for(int j=0;j<s.length();j++){
            if(s[j]=='O'){
                sum+=c++;
            }else{
                c=1;
            }
        }
        a.push_back(sum);
    }
    for(int i:a){
        cout<<i<<"\n";
    }
}

