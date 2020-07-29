#include<iostream>
#include<algorithm>
using namespace std;
long long D[64][127];
long long go(int a,int b){ // count for set b(cm) after a(second) 
    if(b==0)
        return 0;
    if(a==0)
        return 1;
    if(D[a][b]!=-1)
        return D[a][b];
    return D[a][b]=go(a-1,b+1)+go(a-1,b-1);
}
int main(){
    int n,k; // n 은 초 // k 은 수면 m
    cin>>k>>n;
    for(int i=0;i<65;i++)
        for(int j=0;j<65;j++)
            D[i][j]=-1;
    cout<<go(n,k);
}