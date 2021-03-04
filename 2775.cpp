#include<iostream>
#include<vector>
using namespace std;
int d[15][15];
long long sp[15][15];
int main(){
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(i==0){
                d[i][j]=j;
            }
            else{
                d[i][j]=sp[i-1][j];
            }
        }
        for(int j=1;j<15;j++){
            sp[i][j]=sp[i][j-1]+d[i][j];
        }
    }
    int t;
    cin>>t;
    while(t--){
        int k,n;
        cin>>k>>n;
        cout<<d[k][n]<<"\n";
    }
}