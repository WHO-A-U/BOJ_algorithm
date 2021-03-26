#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
using namespace std;
using vb = vector<bool>;
using vvb = vector<vb>;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin>>n;
    vvb map(n,vb(n));
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<n;j++){
            map[i][j] = (s[j]=='T'?true:false);
        }
    }    
    auto origin = map;
    int ans = INF;
    for(int k=0;k<(1<<n);k++){
        map = origin;
        int cur = k;
        for(int j=n-1;j>=0;j--){
            if(cur-(1<<j)>=0){
                cur-=(1<<j);
                for(int i=0;i<n;i++){
                    map[i][j] = !map[i][j];
                }
            }
        }
        int val=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(map[i][j])
                    cnt++;
            }
            val+=min(cnt , n-cnt);
        }
        ans = min(ans , val);
    }
    cout<<ans;

}