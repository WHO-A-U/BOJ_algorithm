#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,l,now=0,ans=0;
    cin>>n>>m>>l;
    vi a(n);
    a[now]++;
    while(1){
        if(a[now]==m) break;
        if(a[now]%2)now = (now+l)%n;
        else now = (n+now-l)%n;
        a[now]++;
        ans++;
    }
    cout<<ans;
}