#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
int d[51][51];
int v[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, l, r, ans = 0;
vector<pair<int, int>> group[2501];
bool bfs() {
    queue<pair<int, int>>q;
    memset(v, -1, sizeof(v));
    int color = 0;
    for (int i = 0; group[i].size() > 0 && i < 2501; i++)
        group[i].clear();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (v[i][j] == -1) {
                q.push({ i,j });
                v[i][j] = color;
                group[color].push_back({ i,j });
                while (!q.empty()) {
                    int cr = q.front().first;
                    int cc = q.front().second;
                    q.pop();
                    for (int i = 0; i < 4; i++) {
                        int nr = cr + dx[i];
                        int nc = cc + dy[i];
                        if (nr >= 1 && nr <= n && nc >= 1 && nc <= n && abs(d[nr][nc] - d[cr][cc]) >= l && abs(d[nr][nc] - d[cr][cc]) <= r && v[nr][nc] == -1) {
                            v[nr][nc] = color;
                            group[color].push_back({ nr,nc });
                            q.push({ nr,nc });
                        }
                    }
                }
                color++;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < color; i++) {
        if (group[i].size() <=1)
            continue;
        int sum = 0;
        for (int j = 0; j < group[i].size(); j++) {
            if (group[i].size() > 1) {
                cnt = 1;
            }
            int y = group[i][j].first;
            int x = group[i][j].second;
            sum += d[y][x];
        }
        sum /= group[i].size();
        for (int j = 0; j < group[i].size(); j++) {
            int y = group[i][j].first;
            int x = group[i][j].second;
            d[y][x] = sum;
        }
    }
    ans += cnt;
    return (cnt > 0 ? true : false);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }
    while (bfs());
    cout << ans;
}