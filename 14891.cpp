#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
string s[4];
int l[4],r[4],t[4];
int roll[4];
bool v[4];
void rotate(){
    for(int i=0;i<4;i++){
        if(roll[i]!=0){
            l[i]=(l[i]-roll[i]+8)%8;
            r[i]=(r[i]-roll[i]+8)%8;
            t[i]=(t[i]-roll[i]+8)%8;
        }
    }
}
void dfs(int nth,int clock){
    roll[nth]=clock;
    v[nth]=true;
    if(clock==0)
        return ;
    if(nth+1<4){
        if(!v[nth+1]){
            if(s[nth][r[nth]]!=s[nth+1][l[nth+1]]){
                dfs(nth+1,-clock);     
            }
        }
    }
    if(nth-1>=0){
        if(!v[nth-1]){
            if(s[nth][l[nth]]!=s[nth-1][r[nth-1]]){
                dfs(nth-1,-clock);
            }
        }
    }
}
int main(){
    for(int i=0;i<4;i++){
        cin>>s[i];
        l[i]=6;
        r[i]=2;
        t[i]=0;
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int nth,clock;
        cin>>nth>>clock;
        memset(v,false,sizeof(v));
        memset(roll,0,sizeof(roll));
        dfs(nth-1,clock);
        rotate();
    }
    int ans=0;
    for(int i=0;i<4;i++){
        if(s[i][t[i]]=='1')
            ans+=(1<<i);
    }
    cout<<ans;
}