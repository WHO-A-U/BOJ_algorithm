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
set<int> d[101][101];
int sr,sc,n,m;
int dx[]={1,1,1,0,0,0,-1,-1,-1};
int dy[]={-1,0,1,-1,0,1,-1,0,1};
bool isDead[10001];
vpii robots;
bool isValid(int r , int c){
    return r>=0&&r<n&&c>=0&&c<m;
}
int getDist(int r1 , int c1 , int r2 , int c2){
    return abs(r1-r2)+abs(c1-c2);
}
bool moveRobotFailCheck(int idx){
    //로봇 번호 idx를 받으면 계산을 하여 맵을 이동한다.
    if(isDead[idx]){
        return true;
    }
    auto robot = robots[idx];
    int r = robot.first;
    int c = robot.second;
    
    d[r][c].erase(idx);
    int minVal=INF,j;
    for(int i=0;i<9;i++){
        int nr = r+dx[i];
        int nc = c+dy[i];
        if(isValid(nr,nc)){
            int dist = getDist(sr,sc,nr,nc);
            if(minVal>dist){
                minVal = dist;
                j=i;
            }
        }
    }
    r+=dx[j];
    c+=dy[j];

    if(r==sr && c==sc){
        // cout<<"@1@";
        return false;
    }

    robots[idx]={r,c};
    d[r][c].insert(idx);

    return true;
    
}
bool moveJSfailCheck(int command){
    int nr = sr+dx[command];
    int nc = sc+dy[command];
    if(!isValid(nr,nc)){
        // cout<<"@2@";
        return false;
    }

    d[sr][sc].clear();
    if(!d[nr][nc].empty()){
        // cout<<"@3@";
        return false;
    }

    d[nr][nc].insert(INF);
    sr = nr;
    sc = nc;
    return true;
    
}
void exploCheck(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(d[i][j].size()>1){
                auto it = d[i][j].begin();
                for(;it!=d[i][j].end();it++){
                    isDead[*it]=true;
                }
                d[i][j].clear();
            }
        }
    }
}
void printFail(int time){
    cout<<"kraj "<<time<<"\n";
}
void printMap(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(sr==i&&sc==j){
                cout<<"I";
            }else if(d[i][j].size()>0){
                cout<<"R";

            }else{
                cout<<".";
            }
        }
        cout<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>n>>m;
    int Rcount=0,time=0;
    memset(isDead,false,sizeof(isDead));
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='R'){
                robots.push_back({i,j});
                d[i][j].insert(Rcount++);
            }
            else if(s[j]=='I'){
                sr = i;
                sc = j;
                d[i][j].insert(INF);
            }
        }
    }
    cin>>s;
    
    for(int time=0;time<s.length();time++){
        if(!moveJSfailCheck((s[time]-'0')-1)){
            printFail(time+1);
            return 0;
        }
        for(int i=0;i<robots.size();i++){
            if(!moveRobotFailCheck(i)){
                printFail(time+1);
                return 0;
            }
        }        
        exploCheck();

    }
    
    printMap();

}
