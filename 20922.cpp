#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,x,ans=0;
    cin>>n>>k;
    map<int,int> m;
    queue<int> q;
    for(int i=0;i<n;i++){
        cin>>x;
        q.push(x);
        m[x]++;
        if(m[x]>k){
            while(m[x]>k&&!q.empty()){
                m[q.front()]--;
                q.pop();
            }
        }
        ans = max(ans,(int)q.size());
    }
    cout<<ans;
}