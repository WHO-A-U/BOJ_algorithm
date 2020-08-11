#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
char d[1501][1501];
int r, c, ans = 0;
int dx[] = { 1,-1,0,0, };
int dy[] = { 0,0,1,-1 };
bool v[1501][1501];
int maxday=0;
int meltingPoint[1501][1501];
vector<pair<int, int>> day[3001];
queue<pair<int, int>> q;
vector<pair<int,int>> L;
bool isPossible(int k) {
    memset(v, false, sizeof(v));
    while(!q.empty())
        q.pop();
    q.push( L[0]);
    v[L[0].first][L[0].first] = true;
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cr + dx[i];
            int nc = cc + dy[i];
            if (nr >= 0 && nr < r && nc >= 0 && nc < c && !v[nr][nc] && meltingPoint[nr][nc]<=k) {
                if (nr ==L[1].first&&nc==L[1].second) {
                    return true;
                }
                v[nr][nc] = true;
                q.push({ nr,nc });
            }
        }
    }
    return false;
}
void melting() {
    memset(v, false, sizeof(v));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            meltingPoint[i][j] = INF;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (d[i][j] != 'X' && meltingPoint[i][j]!=0) {
                meltingPoint[i][j] = 0;
                q.push({ i,j });
            }
        }
    }
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        int cost = meltingPoint[cr][cc];
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cr + dx[i];
            int nc = cc + dy[i];
            if (nr >= 0 && nr < r && nc >= 0 && nc < c) {
                if (d[nr][nc] !='X' && meltingPoint[nr][nc] > cost) {
                    meltingPoint[nr][nc] = cost;
                    q.push({ nr,nc });
                }
                if (d[nr][nc] == 'X' && meltingPoint[nr][nc] > cost + 1) {
                    meltingPoint[nr][nc] = cost + 1;
                    q.push({ nr,nc });
                }
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            maxday=max(maxday,meltingPoint[i][j]);
        }
    }


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < c; j++) {
            d[i][j] = str[j];
            if (d[i][j] == 'L') {
                L.push_back({i,j});
            }
        }
    }
    melting();
    int lo=0,hi=maxday,mid;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(isPossible(mid)){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    cout << lo;


}