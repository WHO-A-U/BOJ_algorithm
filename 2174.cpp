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

int dx[]={1,0,-1,0};//row 변경
int dy[]={0,1,0,-1};//col 변경  북동남서 기준
int getDir(char x){
    if(x=='N')return 0;
    if(x=='E')return 1;
    if(x=='S')return 2;
    return 3;
}
vector<pair<int,pii>> robots;
int d[101][101];
int A,B,n,m;;
bool isValid(int r , int c){
    return r>=1&&r<=B && c>=1&&c<=A;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(d,0,sizeof(d));
    cin>>A>>B;
    cin>>n>>m;
    int col , row;
    char direction;
    robots.push_back({0,{0,0}});
    for(int i=1;i<=n;i++){
        cin>>col>>row>>direction;
        robots.push_back({getDir(direction),{row,col}});
        d[row][col]=i;
    }

    
    int target,count;
    char command;
    while(m--){
        cin>>target>>command>>count;
        while(count--){
            auto robot=robots[target];

            int curDir = robot.first;
            int cr = robot.second.first;
            int cc = robot.second.second;
            if(command=='F'){
                int nr = cr+dx[curDir];
                int nc = cc+dy[curDir];
                if(!isValid(nr,nc)){
                    cout<<"Robot "<<target<<" crashes into the wall";
                    return 0;
                }
                if(d[nr][nc]!=0){
                    cout<<"Robot "<<target<<" crashes into robot "<<d[nr][nc];
                    return 0;
                }

                d[nr][nc]=d[cr][cc];
                d[cr][cc]=0;
                cr = nr;
                cc = nc;
            }else if(command =='R'){
                curDir = (curDir+1)%4;
            }else if(command =='L'){
                curDir = (curDir-1+4)%4;
            }
            robots[target] = {curDir,{cr,cc}};
        }
    }
    cout<<"OK";
    return 0;
    

        
}