#include<iostream>
#include<cstring>
#include<set>
using namespace std;
bool visit[40001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,m,n,x,y;
    cin>>t;
    while(t--){
        cin>>m>>n>>x>>y;
        int delta=0;
        memset(visit,false,sizeof(visit));
        while(x!=1){
            x--;
            y--;
            if(y==0)
                y=n;
            delta++;
        }
        int size = m;
        int cur = 1;
        bool flag=true;
        visit[1]=true;
        int ans=1;
        while(1){
            if(cur==y){
                break;
            }
            if(cur+size>n){
                cur = (cur+size)%n;
                if(cur==0)
                    cur=n;
            }else{
                cur = cur+size;
            }
            if(visit[cur]){
                flag=false;
                break;
            }
            visit[cur]=true;
            ans+=size;
        }
        if(flag){
            cout<<(ans+delta)<<"\n";
        }else{
            cout<<"-1\n";
        }
    }
}