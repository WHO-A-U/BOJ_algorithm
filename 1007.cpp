#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
using pii = pair<int,int>;
using vpii = vector<pii>;
vpii point;
vector<int> op;
double ans;
void cal(){
    long long x=0,y=0;
    for(int i=0;i<point.size();i++){
        x+=point[i].first*op[i];
        y+=point[i].second*op[i];
    }
    double val = sqrt((double)(x*x+y*y));
    ans = min(ans,val);
}
void go(int a,int b){
    if(a==0&&b==0){
        cal();
        return ;
    }
    if(a>0){
        op.push_back(1);
        go(a-1,b);
        op.pop_back();
    }
    if(b>0){
        op.push_back(-1);
        go(a,b-1);
        op.pop_back();
    }
    return ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,n,a,b;
    cin>>t;
    while(t--){
        point.clear();
        ans = 100000000.0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            point.push_back({a,b});
        }
        go(n/2,n/2);
        printf("%lf\n",ans);
    }
}