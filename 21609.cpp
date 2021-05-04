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
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;
vvi board;
bool isValid(int r,  int c){
    return r>=0&&r<n&&c>=0&&c<n;
}
void clearChkRainbow(vvb &arr){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==0){
                arr[i][j]=false;
            }
        }
    }
}
int get_large_board_score_and_remove(){

    vpii criteria;

    int maxSize=2,maxRainbowNum=0;
    vvb chk(n,vb(n,false));
    queue<pii> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!chk[i][j]&&board[i][j]>0&&board[i][j]!=INF){
                q.push({i,j});
                int sz=1;
                int curColor = board[i][j];
                int tr = INF,tc = INF;
                int curRainbowNum=0;
                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    if(board[r][c]==curColor){
                        if(tr>r){
                            tr = r;
                            tc = c;
                        }
                        if(tr==r && tc>c){
                            tc = c;
                        }

                    }
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nr = r+dx[k];
                        int nc = c+dy[k];
                        if(isValid(nr,nc) &&!chk[nr][nc]&& (board[nr][nc]==0||board[nr][nc]==curColor)){
                            q.push({nr,nc});
                            sz++;
                            if(board[nr][nc]==0){
                                curRainbowNum++;
                            }
                            chk[nr][nc]=true;
                        }
                    }
                }
                if(sz>maxSize){
                    maxSize=sz;
                    maxRainbowNum=0;
                    criteria.clear();
                }
                if(sz==maxSize){
                    if(curRainbowNum > maxRainbowNum){
                        maxRainbowNum = curRainbowNum;
                        criteria.clear();
                    }
                    if(curRainbowNum == maxRainbowNum){
                        criteria.push_back({tr,tc});
                    }
                }
                clearChkRainbow(chk);
            }
        }
    }
    sort(all(criteria));
    if(criteria.empty())
        return 0;

    int tr = criteria.back().first;
    int tc = criteria.back().second;

    int color = board[tr][tc];
    chk.assign(n,vb(n,false));
    q.push({tr,tc});
    board[tr][tc] = INF;
    chk[tr][tc]=true;
    int ret=1;
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nr = cr+dx[i];
            int nc = cc+dy[i];
            if(isValid(nr,nc)&&!chk[nr][nc] &&(board[nr][nc]==0||board[nr][nc]==color)){
                ret++;
                chk[nr][nc]=true;
                q.push({nr,nc});
                board[nr][nc]=INF;
            }
        }
    }
    return ret;
}
void activate_gravity(){
    for(int j=0;j<n;j++){
        for(int i=n-1;i>=0;i--){
            if(board[i][j]!=-1&&board[i][j]!=INF){
                int nr=i;
                while(isValid(nr+1,j) && board[nr+1][j]==INF){
                    nr++;
                }
                if(nr!=i){
                    board[nr][j] = board[i][j];
                    board[i][j]=INF;
                }
            }
        }
    }    
}
void rotate_counter_clockwise(){
    vvi newBoard(n,vi(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            newBoard[n-1-j][i] = board[i][j];
        }
    }
    board = newBoard;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;

    board.assign(n,vi(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    int answer=0;
    while(1){
        int score = get_large_board_score_and_remove();
        if(score==0)
            break;
        answer+=(score*score);
        activate_gravity();
        rotate_counter_clockwise();
        activate_gravity();
    }
    cout<<answer;
}