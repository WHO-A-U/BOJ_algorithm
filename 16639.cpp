#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
using vi = vector<int>;
using vc = vector<char>;
vi num;
vc oper;
ll d[21][21][2];
bool ck[21][21][2];
ll cal(ll a, ll b, char op){
    if(op=='*')return a*b;
    if(op=='+')return a+b;
    if(op=='-')return a-b;
}
ll go(int l ,int r,int type){
    if(l==r)
        return num[l];
    
    ll &ret = d[l][r][type];
    bool check = ck[l][r][type];
    if(check){
        return ret;
    }

    ll &maxVal = d[l][r][0], &minVal = d[l][r][1];
    
    maxVal = -INF;
    for(int i=l;i<r;i++){
        maxVal = max(maxVal , cal(go(l,i,0),go(i+1,r,0),oper[i]));
        maxVal = max(maxVal , cal(go(l,i,0),go(i+1,r,1),oper[i]));
        maxVal = max(maxVal , cal(go(l,i,1),go(i+1,r,0),oper[i]));
        maxVal = max(maxVal ,cal(go(l,i,1),go(i+1,r,1),oper[i]));
    }
    ck[l][r][0]=true;

    minVal = INF;
    for(int i=l;i<r;i++){
        minVal = min(minVal , cal(go(l,i,0),go(i+1,r,0),oper[i]));
        minVal = min(minVal , cal(go(l,i,0),go(i+1,r,1),oper[i]));
        minVal = min(minVal , cal(go(l,i,1),go(i+1,r,0),oper[i]));
        minVal = min(minVal ,cal(go(l,i,1),go(i+1,r,1),oper[i]));
    }
    ck[l][r][1]=true;

    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(d,-1,sizeof(d));
    memset(ck,false,sizeof(ck));
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            num.push_back(s[i]-'0');
        }else{
            oper.push_back(s[i]);
        }
    }
    cout<<go(0,n/2,0);
}