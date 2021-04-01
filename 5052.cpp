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

   int t;
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       vs ss;
       string s;

       for(int i=0;i<n;i++){
           cin>>s;
           ss.push_back(s);
       }

       sort(all(ss));
       
       bool flag=true;
       for(int i=1;i<n;i++){
           if(ss[i-1].length()>=ss[i].length()){
               continue;
           }else{
               if(ss[i].substr(0,ss[i-1].length())==ss[i-1]){
                   flag=false;
                   break;
               }
           }
       }
       cout<<(flag?"YES":"NO")<<"\n";
   }
}