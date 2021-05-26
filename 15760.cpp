#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using vi = vector<int>;
vi num;
vi numsSorted;
map<int,int> lastIdx;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x,ans=0;
    cin>>n;
    num.assign(n,0);
    numsSorted.assign(n,0);
    for(int i=0;i<n;i++){
        cin>>num[i];
        numsSorted[i] = num[i];
    }
    sort(all(numsSorted));

    for(int i=0;i<n;i++){
        int cur = numsSorted[i];
        lastIdx[cur]=i;
    }

    for(int i=0;i<n;i++){
        int last = lastIdx[num[i]];
        
        if(last < i){
            ans = max(ans , i-last);
        }
    }
    
    cout<<ans+1;
    
}