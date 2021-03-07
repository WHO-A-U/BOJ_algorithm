#include<iostream>
#include<algorithm>
using namespace std;
string d[101][101];
string sum(string a,string b){
    int c=0;
    int nc=0;
    string s="";

    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    for(int i=0;i<min(a.length(),b.length());i++){
        int A = a[i]-'0';
        int B = b[i]-'0';
        nc=(A+B+c)/10;
        s = (char)(((A+B+c)%10)+'0') +s;
        c = nc;
    }

    for(int i=a.length();i<b.length();i++){
        int x = b[i]-'0';
        nc = (x+c)/10;
        s = (char)(((x+c)%10)+'0') +s;
        c=nc;
    }

    for(int i=b.length();i<a.length();i++){
        int x = a[i]-'0';
        nc = (x+c)/10;
        s = (char)(((x+c)%10)+'0') +s;
        c=nc;
    }
    if(c==1){
        s = "1"+s;
    }

    return s;
}
string go(int a,int b){
    if(a==b||b==0){
        return "1";
    }
    if(d[a][b]!="-1")return d[a][b];
    return d[a][b]=sum(go(a-1,b),go(a-1,b-1));
}
int main(){
    int n,m;
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            d[i][j]="-1";
        }
    }
    cin>>n>>m;
    cout<<go(n,m);
    
}