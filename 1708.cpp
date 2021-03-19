#include <bits/stdc++.h>
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
int n;
struct point{
    ll x,y;
};
vector<point> p;

bool pointCmp( point a , point b){
    if(a.y == b.y)return a.x<b.x;
    return a.y<b.y;

}
ll ccw( point a ,  point  b ,  point c){
    return a.x * b.y + b.x *c.y + c.x*a.y -(b.x*a.y + c.x*b.y + a.x*c.y);
}

bool ccwCmp( point a ,  point b){
    ll val = ccw(p[0], a, b);
    if (val == 0)
         return (a.x + a.y) < (b.x + b.y);
    return val > 0;
}

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   
   cin>>n;
   
   ll x,y;
   p.resize(n);
   for(int i=0;i<n;i++){
       cin>>p[i].x>>p[i].y;
   }

   sort(p.begin(),p.end(),pointCmp);
   sort(p.begin()+1,p.end(),ccwCmp);

   vector<point> ans;
   ans.push_back(p[0]);
   ans.push_back(p[1]);
   for(int i=2;i<n;i++){
       
       while(ans.size()>=2){
           point p2 = ans.back();
           ans.pop_back();
           point p1 = ans.back();

           if(ccw(p1,p2,p[i])>0){
               ans.push_back(p2);
               break;
           }
       }
       ans.push_back(p[i]);
   }
   cout<<ans.size();

}
