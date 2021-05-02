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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin>>n;
    stack<pii> st;
    vi answer(n);
    for(int i=0;i<n;i++){
        cin>>x;
        if(st.empty()){
            st.push({x,i});
        }else{
            while(!st.empty() && st.top().first <x){
                answer[st.top().second] = x;
                st.pop();           
            }
            st.push({x,i});
        }
    }
    while(!st.empty()){
        int idx = st.top().second;
        answer[idx]=-1;
        st.pop();
    }
    for(int i=0;i<n;i++){
        cout<<answer[i]<<" ";
    }
}