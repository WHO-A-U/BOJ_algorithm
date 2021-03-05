#include<iostream>
#include<vector>
#define MAX 100001
#define MAX_D 30
using namespace std;
int d[MAX][MAX_D];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k,m;
    cin>>n>>k>>m;
    vector<int> student(n);
    for(int i=0;i<n;i++){
        cin>>student[i];
    }
    for(int i=1;i<=k;i++){
        cin>>d[i][0];
    }

    for(int i=1;i<MAX_D;i++){
        for(int j=1;j<=k;j++){
            d[j][i] = d[d[j][i-1]][i-1];
        }
    }

    for(int i=0;i<n;i++){
        int tmpM = m;
        int cur = student[i];
        for(int b=MAX_D;b>=0;b--){
            if((tmpM-(1<<b))>0){
                tmpM-=(1<<b);
                cur = d[cur][b];
            }
        }
        cout<<cur<<" ";
    }
}