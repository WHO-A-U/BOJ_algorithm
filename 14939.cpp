#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<cmath>
#include<set>
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vs = vector<string>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vvi = vector<vi>;

vvb origin(10,vb(10));
vvb map;
int dx[]={0,1,-1,0,0};
int dy[]={0,0,0,1,-1};
void switchCell(int r , int c){
    for(int i=0;i<5;i++){
        int nr = r+dx[i];
        int nc = c+dy[i];
        if(nr>=0&&nr<10&&nc>=0&&nc<10){
            map[nr][nc]=!map[nr][nc];
        }
    }
}
bool isSatisfy(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(map[i][j]){
                return false;
            }
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    for(int i=0;i<10;i++){
        cin>>s;
        for(int j=0;j<10;j++){
            origin[i][j]=(s[j]=='O'?true:false);
        }
    }

    int cnt,ans=INF;
    for(int k=0;k<(1<<10);k++){
        cnt=0;
        map=origin;
        int bits = k;
        for(int i=9;i>=0;i--){
            if(bits-(1<<i)>=0){
                bits-=(1<<i);
                cnt++;
                switchCell(0,i);
            }
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<10;j++){
                if(map[i][j]){
                    cnt++;
                    switchCell(i+1,j);
                }
            }
        }

        if(isSatisfy()){
            ans = min(ans , cnt);
        }

    }
    if(ans==INF){
        cout<<"-1";
    }else{
        cout<<ans;
    }

}

