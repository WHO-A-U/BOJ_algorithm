#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using pii = pair<int, int>;
using dpii = deque<pii>;
int cnt[101];
bool cmp(const pii &a , const pii &b){
    if(cnt[a.first]<cnt[b.first])return true;
    if(cnt[a.first]>cnt[b.first])return false;
    if(a.second<b.second)return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,x;
    cin>>n>>m;
    dpii d;

    for(int i=0;i<m;i++){
        cin>>x;
        if(cnt[x]==0){
            if(d.size()==n){
                cnt[d[0].first]=0;
                d.pop_front();
            }
            d.push_front({x,i});
        }
        cnt[x]++;
        sort(all(d),cmp);
    }

    sort(all(d));
    for(auto a: d){
        if(a.first!=0){
            cout<<a.first<<" ";
        }
    }
}