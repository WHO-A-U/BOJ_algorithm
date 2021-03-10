#include<bits/stdc++.h>
using namespace std;
string d[1001][1001];
int main(){
    string a,b;
    cin>>a>>b;
    a="0"+a;
    b="0"+b;
    int la = a.length(),lb=b.length();

    for(int i=0;i<lb;i++){
        for(int j=0;j<la;j++){
            d[i][j]="";
        }
    }

    for(int i=1;i<lb;i++){
        for(int j=1;j<la;j++){
            if(a[j]==b[i]){
                d[i][j]=d[i-1][j-1]+a[j];
            }else{
                if(d[i-1][j].length()>d[i][j-1].length()){
                    d[i][j]=d[i-1][j];
                }else{
                    d[i][j]=d[i][j-1];
                }
            }
        }
    }
    cout<<d[lb-1][la-1].length()<<"\n";
    cout<<d[lb-1][la-1];
}