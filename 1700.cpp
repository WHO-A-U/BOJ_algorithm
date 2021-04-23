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
int n,k,ans=0;
deque<int> idxs[101];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    vi task(k);
    for(int i=0;i<k;i++){
        cin>>task[i];
        idxs[task[i]].push_back(i);
    }
    map<int,int> m;
    for(int i=0;i<k;i++){
        if(m.find(task[i])==m.end()&&m.size()==n){
            int maxVal=0,target;
            for(auto it = m.begin();it!=m.end();it++){
                int num = it->first;
                if(idxs[num].size()==0){
                    target = num;
                    break;
                }else{
                    if(idxs[num].front() > maxVal){
                        maxVal = idxs[num].front();
                        target = num;
                    }
                }
            }
            m.erase(target);
            ans++;
        }
        m[task[i]]=1;
        idxs[task[i]].pop_front();
    }
    cout<<ans;
    
    
}