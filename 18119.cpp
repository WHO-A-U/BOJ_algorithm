#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,x,cnt;
    string s;
    char ch;
    cin>>n>>m;
    vector<int> d(n);

    for(int i=0;i<n;i++){
        cin>>s;
        x=0;
        for(char c : s){
            x|=(1<<(c-'a'));
        }
        d[i]=x;
    }
    int cur = 0xfffffff;

    while(m--){
        cnt=0;
        cin>>x>>ch;
        if(x==1){
            cur^=(1<<(ch-'a'));
        }else{
            cur|=(1<<(ch-'a'));
        }
        for(int x:d){
            if((x&cur) == x){
                cnt++;
            }
        }
        cout<<cnt<<"\n";

    }
}