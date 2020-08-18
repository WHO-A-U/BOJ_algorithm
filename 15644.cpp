#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
char d[11][11];
int n, m;
int row[3], col[3];
//red blue goal
struct Stage {
    int rr, rc;
    int br, bc;
    int cnt;
    string s;
    Stage(int rr, int rc, int br, int bc, int cnt,string s) :rr(rr), rc(rc), br(br), bc(bc), cnt(cnt), s(s){}
};
pair<int, int> up(int r, int c, int color) {
    while (d[r - 1][c] != '#' && (d[r-1][c]=='O'||!(r - 1 == row[1 - color] && c == col[1 - color]))) {
        r--;
        if (d[r][c] == 'O')
            break;
    }
    return { r,c };
}
pair<int, int> down(int r, int c, int color) {
    while (d[r + 1][c] != '#' && (d[r+1][c]=='O'||!(r + 1 == row[1 - color] && c == col[1 - color]))) {
        r++;
        if (d[r][c] == 'O')
            break;
    }
    return { r,c };
}
pair<int, int> right(int r, int c, int color) {
    while (d[r][c + 1] != '#' && (d[r][c+1]=='O'||!(r == row[1 - color] && c + 1 == col[1 - color]))) {
        c++;
        if (d[r][c] == 'O')
            break;
    }
    return { r,c };
}
pair<int, int> left(int r, int c, int color) {
    while (d[r][c - 1] != '#' && (d[r][c-1]=='O'||!(r == row[1 - color] && c - 1 == col[1 - color]))) {
        c--;
        if (d[r][c] == 'O')
            break;
    }
    return { r,c };
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            d[i][j] = s[j];
            if (s[j] == 'R') {
                d[i][j] = '.';
                row[0] = i;
                col[0] = j;
            }
            if (s[j] == 'B') {
                d[i][j] = '.';
                row[1] = i;
                col[1] = j;
            }
            if (s[j] == 'O') {
                row[2] = i;
                col[2] = j;
            }
        }
    }
    queue<Stage> q;
    q.push(Stage(row[0], col[0], row[1], col[1], 0,""));
    while (!q.empty()) {
        row[0] = q.front().rr;
        col[0] = q.front().rc;
        row[1] = q.front().br;
        col[1] = q.front().bc;
        int cnt = q.front().cnt;
        string str = q.front().s;
        q.pop();
        if (cnt >= 10) {
            continue;
        }
        if (row[0] <= row[1]) {//up 구현
            int sr1 = row[0], sc1 = col[0];
            int sr2 = row[1], sc2 = col[1];
            auto tmp1 = up(row[0], col[0], 0);
            row[0] = tmp1.first;
            col[0] = tmp1.second;
            auto tmp2 = up(row[1], col[1], 1);
            row[1] = tmp2.first;
            col[1] = tmp2.second;
            if (row[0] == row[2] && col[0] == col[2] && !(row[1] == row[2] && col[1] == col[2])) {
                cout << cnt + 1;
                cout<<'\n'<<str+'U';
                return 0;
            }
            if (!(row[1] == row[2] && col[1] == col[2])&&!(row[0] == sr1 && col[0] == sc1 && row[1] == sr2 && col[1] == sc2))
                q.push(Stage(row[0], col[0], row[1], col[1], cnt + 1,str+"U"));
            row[0] = sr1;
            col[0] = sc1;
            row[1] = sr2;
            col[1] = sc2;
        }
        else {
            int sr1 = row[0], sc1 = col[0];
            int sr2 = row[1], sc2 = col[1];
            auto tmp2 = up(row[1], col[1], 1);
            row[1] = tmp2.first;
            col[1] = tmp2.second;
            auto tmp1 = up(row[0], col[0], 0);
            row[0] = tmp1.first;
            col[0] = tmp1.second;
            if (row[0] == row[2] && col[0] == col[2] && !(row[1] == row[2] && col[1] == col[2])) {
                cout << cnt + 1;
                cout<<'\n'<<str+'U';
                return 0;
            }
            if (!(row[1] == row[2] && col[1] == col[2]) && !(row[0] == sr1 && col[0] == sc1 && row[1] == sr2 && col[1] == sc2))
                q.push(Stage(row[0], col[0], row[1], col[1], cnt + 1,str+"U"));
            row[0] = sr1;
            col[0] = sc1;
            row[1] = sr2;
            col[1] = sc2;
        }
        if (row[0] >= row[1]) {//down 구현
            int sr1 = row[0], sc1 = col[0];
            int sr2 = row[1], sc2 = col[1];
            auto tmp1 = down(row[0], col[0], 0);
            row[0] = tmp1.first;
            col[0] = tmp1.second;
            auto tmp2 = down(row[1], col[1], 1);
            row[1] = tmp2.first;
            col[1] = tmp2.second;
            if (row[0] == row[2] && col[0] == col[2] && !(row[1] == row[2] && col[1] == col[2])) {
                cout << cnt + 1;
                cout<<'\n'<<str+'D';
                return 0;
            }
            if (!(row[1] == row[2] && col[1] == col[2]) && !(row[0] == sr1 && col[0] == sc1 && row[1] == sr2 && col[1] == sc2))
                q.push(Stage(row[0], col[0], row[1], col[1], cnt + 1,str+"D"));
            row[0] = sr1;
            col[0] = sc1;
            row[1] = sr2;
            col[1] = sc2;
        }
        else {
            int sr1 = row[0], sc1 = col[0];
            int sr2 = row[1], sc2 = col[1];
            auto tmp2 = down(row[1], col[1], 1);
            row[1] = tmp2.first;
            col[1] = tmp2.second;
            auto tmp1 = down(row[0], col[0], 0);
            row[0] = tmp1.first;
            col[0] = tmp1.second;
            if (row[0] == row[2] && col[0] == col[2] && !(row[1] == row[2] && col[1] == col[2])) {
                cout << cnt + 1;
                cout<<'\n'<<str+'D';
                return 0;
            }
            if (!(row[1] == row[2] && col[1] == col[2]) && !(row[0] == sr1 && col[0] == sc1 && row[1] == sr2 && col[1] == sc2))
                q.push(Stage(row[0], col[0], row[1], col[1], cnt + 1,str+"D"));
            row[0] = sr1;
            col[0] = sc1;
            row[1] = sr2;
            col[1] = sc2;
        }
        if (col[0] >= col[1]) {//right 구현
            int sr1 = row[0], sc1 = col[0];
            int sr2 = row[1], sc2 = col[1];
            auto tmp1 = right(row[0], col[0], 0);
            row[0] = tmp1.first;
            col[0] = tmp1.second;
            auto tmp2 = right(row[1], col[1], 1);
            row[1] = tmp2.first;
            col[1] = tmp2.second;
        
            if (row[0] == row[2] && col[0] == col[2] && !(row[1] == row[2] && col[1] == col[2])) {
                cout << cnt + 1;
                cout<<'\n'<<str+'R';
                return 0;
            }
            if (!(row[1] == row[2] && col[1] == col[2]) && !(row[0] == sr1 && col[0] == sc1 && row[1] == sr2 && col[1] == sc2))
                q.push(Stage(row[0], col[0], row[1], col[1], cnt + 1,str+"R"));
            row[0] = sr1;
            col[0] = sc1;
            row[1] = sr2;
            col[1] = sc2;
        }
        else {
            int sr1 = row[0], sc1 = col[0];
            int sr2 = row[1], sc2 = col[1];
            auto tmp2 = right(row[1], col[1], 1);
            row[1] = tmp2.first;
            col[1] = tmp2.second;
            auto tmp1 = right(row[0], col[0], 0);
            row[0] = tmp1.first;
            col[0] = tmp1.second;
            
            if (row[0] == row[2] && col[0] == col[2] && !(row[1] == row[2] && col[1] == col[2])) {
                cout << cnt + 1;
                cout<<'\n'<<str+'R';
                return 0;
            }
            if (!(row[1] == row[2] && col[1] == col[2]) && !(row[0] == sr1 && col[0] == sc1 && row[1] == sr2 && col[1] == sc2))
                q.push(Stage(row[0], col[0], row[1], col[1], cnt + 1,str+"R"));
            row[0] = sr1;
            col[0] = sc1;
            row[1] = sr2;
            col[1] = sc2;
        }
        if (col[0] <= col[1]) {//left 구현
            int sr1 = row[0], sc1 = col[0];
            int sr2 = row[1], sc2 = col[1];
            auto tmp1 = left(row[0], col[0], 0);
            row[0] = tmp1.first;
            col[0] = tmp1.second;
            auto tmp2 = left(row[1], col[1], 1);
            row[1] = tmp2.first;
            col[1] = tmp2.second;
            if (row[0] == row[2] && col[0] == col[2] && !(row[1] == row[2] && col[1] == col[2])) {
                cout << cnt + 1;
                cout<<'\n'<<str+'L';
                return 0;
            }
            if (!(row[1] == row[2] && col[1] == col[2]) && !(row[0] == sr1 && col[0] == sc1 && row[1] == sr2 && col[1] == sc2))
                q.push(Stage(row[0], col[0], row[1], col[1], cnt + 1,str+"L"));
            row[0] = sr1;
            col[0] = sc1;
            row[1] = sr2;
            col[1] = sc2;
        }
        else {
            int sr1 = row[0], sc1 = col[0];
            int sr2 = row[1], sc2 = col[1];
            auto tmp2 = left(row[1], col[1], 1);
            row[1] = tmp2.first;
            col[1] = tmp2.second;
            auto tmp1 = left(row[0], col[0], 0);
            row[0] = tmp1.first;
            col[0] = tmp1.second;
            if (row[0] == row[2] && col[0] == col[2] && !(row[1] == row[2] && col[1] == col[2])) {
                cout << cnt + 1;
                cout<<'\n'<<str+'L';
                return 0;
            }
            if (!(row[1] == row[2] && col[1] == col[2]) && !(row[0] == sr1 && col[0] == sc1 && row[1] == sr2 && col[1] == sc2))
                q.push(Stage(row[0], col[0], row[1], col[1], cnt + 1,str+"L"));
            row[0] = sr1;
            col[0] = sc1;
            row[1] = sr2;
            col[1] = sc2;
        }
    }
    cout << "-1";
}



