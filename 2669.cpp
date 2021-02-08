#include<iostream>
int d[101][101];
using namespace std;
int main(){
    int x1,y1,x2,y2,ans=0;
    for(int i=0;i<4;i++){
        cin>>x1>>y1>>x2>>y2;
        for(int j=x1;j<x2;j++){
            for(int k=y1;k<y2;k++){
                d[j][k]++;
            }
        }
    }
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            if(d[i][j]>0){
                ans++;
            }
        }
    }
    cout<<ans;
}