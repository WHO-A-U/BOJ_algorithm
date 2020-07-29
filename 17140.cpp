#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int d[101][101];
int r, c, k, n = 0;
int row = 3, col = 3;
int val = 0;
bool cmpr(pair<int, int>& a, pair<int, int>& b) {
    if (a.second < b.second)
        return true;
    if (a.second == b.second && a.first < b.first) {
        return true;
    }
    return false;
}
void Rcal(int ridx) {
    map<int, int> m;
    vector<pair<int, int>> v;
    for (int i = 1; i <= col; i++) {
        if (d[ridx][i] == 0)
            continue;
        if (m.find(d[ridx][i]) == m.end())
            m[d[ridx][i]] = 1;
        else
            m[d[ridx][i]]++;
    }
    for (auto i = m.begin(); i != m.end(); i++) {
        v.push_back({ i->first,i->second }); //first 가 수 , second 가 횟수
    }
    sort(v.begin(), v.end(), cmpr);
    val = max((int)(v.size() * 2), val);
    for (int i = 1, j = 0; i < 100; i += 2) {
        if (j < v.size()) {
        d[ridx][i] = v[j].first;
        d[ridx][i + 1] = v[j].second;
        }
        else {
            d[ridx][i] = d[ridx][i + 1] = 0;
        }
        
        j++;
    }
}
void Ccal(int cidx) {
    map<int, int> m;
    vector<pair<int, int>> v;
    for (int i = 1; i <= row; i++) {
        if (d[i][cidx] == 0)
            continue;
        if (m.find(d[i][cidx]) == m.end())
            m[d[i][cidx]] = 1;
        else
            m[d[i][cidx]]++;
    }
    for (auto i = m.begin(); i != m.end(); i++) {
        v.push_back({ i->first,i->second }); //first 가 수 second 가 횟수
    }
    sort(v.begin(), v.end(), cmpr);
    val = max((int)(v.size() * 2), val);
    for (int i = 1; i <= row; i++) {
        d[i][cidx] = 0;
    }
    for (int i = 1, j = 0; i < 100; i += 2) {
        if (j < v.size()) {
        d[i][cidx] = v[j].first;
        d[i+1][cidx] = v[j].second;
        }
         else {
         d[i][cidx] = d[i+1][cidx] = 0;
        }

        j++;
    }
  
}
void nextSecond() {
    val = 0;
    if (row >= col) {
        for (int i = 1; i <= row; i++) {
            Rcal(i);
        }
        col = val;
    }
    else {
        for (int i = 1; i <= col; i++) {
            Ccal(i);
        }
        row = val;
    }
}
int main() {
    cin >> r >> c >> k;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> d[i][j];
        }
    }
    while (n <= 100) {
        if (d[r][c] == k) {
            cout << n;
            break;
        }
        nextSecond();
        n++;
    }
    if (n > 100)
        cout << -1;
}