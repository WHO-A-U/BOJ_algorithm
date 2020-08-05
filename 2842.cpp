#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<cstring>
using namespace std;
char m[51][51];
int d[51][51];
int v[51][51]; // 가장 낮은곳 0 가장 높은곳 1
int dx[] = { 1,1,1,0,0,-1,-1,-1 };
int dy[] = { 1,0,-1,1,-1,1,0,-1 };
int hcnt = 0;
int lo, hi, n;
vector<pair<int, int>>home;
void dfs(int r, int c) {
    if (r >= 0 && r < n && c >= 0 && c < n && !v[r][c] && d[r][c] >= lo && d[r][c] <= hi) {
        v[r][c] = true;
        for (int i = 0; i < 8; i++) {
            dfs(r + dx[i], c + dy[i]);
        }
    }
    return;
}
bool isPossible() {
    for (int i = 0; i < hcnt; i++) {
        if (v[home[i].first][home[i].second] == false)
            return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int sr=0, sc=0;
    cin >> n;
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
            if (m[i][j] == 'P') {
                sr = i;
                sc = j;
            }
            if (m[i][j] == 'K') {
                home.push_back({ i,j });
                hcnt++;
            }
        }
    }
    set <int> height;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
            height.insert(d[i][j]);
        }
    }
    auto l = height.begin();
    auto r = height.begin();
    int ans = 0x3f3f3f3f;
    for(;r!=height.end();r++) {
        for(;l!=height.end();l++) {
            memset(v, false, sizeof(v));
            lo = *l;
            hi = *r;
            dfs(sr, sc);
            if (!isPossible())
                break;
            ans = min(ans, hi-lo);
        }
    }
    cout << ans;
}