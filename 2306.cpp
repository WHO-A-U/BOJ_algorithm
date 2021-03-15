#include <bits/stdc++.h>
using namespace std;
int d[501][501];
string s;
bool isKOI(char a,char b){
    if((a=='a'&&b=='t')||(a=='g'&&b=='c'))return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    int n = s.length();

    for(int k=1;k<n;k++){
        for(int i=0;i+k<n;i++){
            if(isKOI(s[i],s[i+k])){
                d[i][i+k]=d[i+1][i+k-1]+2;
            }
            for(int j=i;j<i+k;j++){
                d[i][i+k] = max(d[i][i+k],d[i][j]+d[j+1][i+k]);
            }
        }
    }
    cout<<d[0][n-1];
}