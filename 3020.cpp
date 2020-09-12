#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int down[500002];
int up[500002];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,h;
    int a,b;
    cin>>n>>h;
    for(int i=0;i<n/2;i++){
        cin>>a>>b;
        down[a]++;
        up[b]++;  
    }
    for(int i=h-1;i>0;i--){
        down[i]+=down[i+1];
        up[i]+=up[i+1];
    }
    int minval=987654321;
    int cnt=0;
    for(int i=1;i<=h;i++){
        int cur = down[i]+up[h-i+1];
        if(minval==cur)
            cnt++;
        if(minval>cur){
            cnt=1;
            minval=cur;
        }
    }
    cout<<minval<<" "<<cnt;
}