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

string m[10];
int n;
vpii ts;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool isValid(int r, int c){
    return (0<=r && r<n && 0<=c && c<n);
}
bool isPossible(vector<vector<char>> map){
    for(auto t : ts){
        for(int i=0;i<4;i++){
            int r = t.first+dx[i];
            int c = t.second+dy[i];
            while(isValid(r,c)){
                if(map[r][c]=='S'){
                    return false;
                }
                if(map[r][c]=='O'){
                    break;
                }
                r+=dx[i];
                c+=dy[i];
            }
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<vector<char>> map(n,vector<char>(n));

    string s;
    char c;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>c;
            if(c=='T'){
                ts.emplace_back(i,j);
            }
            map[i][j] = c;
        }
    }
    
    auto mapOrigin = map;


    int MAX_CELL = n*n;
    bool flag=false;
    for(int i=0;i<MAX_CELL;i++){
        for(int j=i+1;j<MAX_CELL;j++){
            for(int k=j+1;k<MAX_CELL;k++){
                if(mapOrigin[i/n][i%n]=='X'&&mapOrigin[j/n][j%n]=='X'&&mapOrigin[k/n][k%n]=='X'){
                    map = mapOrigin;
                    map[i/n][i%n]='O';
                    map[j/n][j%n]='O';
                    map[k/n][k%n]='O';
                    if(isPossible(map)){
                        flag=true;
                        break;
                    }
                }
            }
            if(flag){
                break;
            }
        }
        if(flag){
            break;
        }
    }
    if(flag){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    
}