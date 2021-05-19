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

ll d[100001];
vi e[100001];
vi edir[100001];
bool chk[100001];


pll getGroupCount(int idx,ll maxCnt){ // first : 개별의 갯수 , second : 군집의 갯수
    pll tmp = {(ll)d[idx],0LL};
    chk[idx]=true;
    vpll childs ;
    for(auto next :edir[idx]){
        if(!chk[next])
            childs.push_back(getGroupCount(next,maxCnt));
    }

    sort(all(childs));

    for(auto child : childs){
        if(tmp.first + child.first <= maxCnt){
            tmp.first += child.first;
        }else{
            tmp.second += 1;
        }
        tmp.second += child.second;
    }

    return tmp;

}

void go(int idx){
    chk[idx]=true;    
    for(auto next : e[idx]){
        if(!chk[next]){
            edir[idx].push_back(next);
            go(next);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t,n,k,x,y;
    cin>>t;
    while(t--){
        cin>>n>>k;
        k++;
        memset(d,0,sizeof(d));
        memset(chk,false,sizeof(chk));

        ll sum=0,minVal=0;
        for(int i=1;i<=n;i++){
            cin>>d[i];
            sum+=d[i];
            minVal = max(minVal , (ll)d[i]);
            e[i].clear();
            edir[i].clear();
        }
        
        for(int i=0;i<n-1;i++){
            cin>>x>>y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        
        /////그래프 -> 트리로.
        go(1);
        /////


        //묶이는 명수들중 최대가 몇명일까?
        ll l=minVal,r=sum,mid,ans=0x3f3f3f3f3f3f3f3f;
        while(l<=r){
            memset(chk,false,sizeof(chk));
            mid = (l+r)/2;
            auto result = getGroupCount(1,mid);
            ll need = (result.first > 0 ? result.second+1 : result.second);
            if( k >= need){
                ans = min(ans , mid);
                r = mid-1;
            }else if(k<need){
                l = mid+1;
            }
        }
        cout<<ans<<"\n";
    }
}