#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vs = vector<string>;
using vd = vector<double>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vvpii = vector<vpii>;
using vvpll = vector<vpll>;
using vvs = vector<vs>;

int v[800000][2];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int w,n;
    cin>>w>>n;
    
    vi d(n);
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    sort(d.begin(),d.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(d[i]+d[j]<w&&v[d[i]+d[j]][1]==0){
                v[d[i]+d[j]][0]=i;
                v[d[i]+d[j]][1]=j;
            }
        }
    }

    bool flag=false;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(d[i]+d[j]<w&&(w-(d[i]+d[j]))>=2){
                if(v[w-(d[i]+d[j])][1]!=0){
                    if(i!=v[w-(d[i]+d[j])][0]&&j!=v[w-(d[i]+d[j])][1]&&j!=v[w-(d[i]+d[j])][0]&&i!=v[w-(d[i]+d[j])][1]){
                        flag=true;
                    }
                }
            }
        }
    }
    if(flag){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}