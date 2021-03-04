#include<iostream>
#include<vector>
#define mod 1000000007
using namespace std;
using vvi = vector<vector<int>>;
long long d[100001][9];
vvi p = {
        {},
        {2, 3},
        {1, 3, 4},
        {1, 2, 4, 5},
        {2, 3, 5, 6},
        {3, 4, 6, 8},
        {4, 5, 7},
        {6, 8},
        {5, 7},
};
int main(){
    int n;
    cin>>n;
    d[0][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=8;j++){
            long long tmp=0;
            for(int x: p[j]){
                tmp+=d[i-1][x];
            }
            tmp%=mod;
            d[i][j]=tmp;
        }
    }
    cout<<d[n][1];
}