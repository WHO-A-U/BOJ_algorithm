#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool s[101];
void switchMan(int idx , int n){
    for(int i=idx;i<=n;i+=idx)
        s[i]=!s[i];
}
void switchWoman(int idx , int n){
    int l=idx,r=idx;
    while(1){
        if(r+1>n||l-1<1){
            break;
        }
        if(s[r+1]!=s[l-1]){
            break;
        }
        r+=1;
        l-=1;
    }
    for(int i=l;i<=r;i++){
        s[i]=!s[i];
    }
}
int main(){
    int n,m,x,y;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        s[i]=x==1?true:false;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        if(x==1)
            switchMan(y,n);
        else
            switchWoman(y,n);
    }
    for(int i=1;i<=n;i++){
        cout<<s[i]<<" ";
        if(i%20==0){
            cout<<"\n";
        }
    }
}