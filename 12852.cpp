#include<iostream>
#include<algorithm>
#define INF 0x3f3f3f3f;
#define MAX 1000001
using namespace std;
int d[MAX][2];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<MAX;i++){
        d[i][0]=INF;
    }
    d[1][0]=0;
    for(int i=1;i<=n;i++){
        if(i*2<=n){
            if(d[i*2][0]>d[i][0]+1){
                d[i*2][0]=d[i][0]+1;
                d[i*2][1]=2;
            }
        }
        if(i*3<=n){
            if(d[i*3][0]>d[i][0]+1){
                d[i*3][0]=d[i][0]+1;
                d[i*3][1]=3;
            }
        }
        if(i+1<=n){
            if(d[i+1][0]>d[i][0]+1){
                d[i+1][0]=d[i][0]+1;
                d[i+1][1]=1;
            }
        }
    }
    cout<<d[n][0]<<"\n";
    cout<<n<<" ";
    while(n!=1){
        if(d[n][1]==1){
            n-=1;
        }
        else if(d[n][1]==2){
            n/=2;
        }
        else if(d[n][1]==3){
            n/=3;
        }
        cout<<n<<" ";
    }

}
