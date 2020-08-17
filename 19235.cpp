#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
using namespace std;
int m[12][12];
int cnt = 0, k, t, r, c;
vector<pair<int, int>> casePoint[3];
int id = 1;
void printAll() {
    cout << '\n';
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << m[i][j] << " ";
            // cout<<(m[i][j]>0?1:0)<<" ";
        }
        cout << '\n';
    }
}
void insert(int blockCase, int row, int col) {
    if (blockCase == 1) {
        for (int i = 4; i < 9; i++) {
            if (m[row][i + 1] > 0) {
                m[row][i] = id++;
                break;
            }
            if (i == 8) {
                m[row][9] = id++;
                break;
            }
        }
        for (int i = 4; i < 9; i++) {
            if (m[i + 1][col] > 0) {
                m[i][col] = id++;
                break;
            }
            if (i == 8) {
                m[9][col] = id++;
                break;
            }
        }
    }
    else if (blockCase == 2) {
        for (int i = 4; i < 9; i++) {
            if (m[row][i + 1] > 0) {
                m[row][i] = m[row][i - 1] = id++;;
                break;
            }
            if (i == 8) {
                m[row][9] = m[row][8] = id++;
                break;
            }
        }
        for (int i = 4; i < 9; i++) {
            if (m[i + 1][col] > 0 || m[i + 1][col + 1] > 0) {
                m[i][col] = m[i][col + 1] = id++;
                break;
            }
            if (i == 8) {
                m[9][col] = m[9][col + 1] = id++;
                break;
            }
        }
    }
    else if (blockCase == 3) {
        for (int i = 4; i < 9; i++) {
            if (m[row][i + 1] > 0 || m[row + 1][i + 1] > 0) {
                m[row][i] = m[row + 1][i] = id++;
                break;
            }
            if (i == 8) {
                m[row][9] = m[row + 1][9] = id++;
                break;
            }
        }
        for (int i = 4; i < 9; i++) {
            if (m[i + 1][col] > 0) {
                m[i][col] = m[i - 1][col] = id++;
                break;
            }
            if (i == 8) {
                m[9][col] = m[8][col] = id++;
                break;
            }
        }
    }
}
bool isBigBlock(int r, int c, int color) {
    int tmp = m[r][c];
    if (color == 0) {//green
        int dx[] = { -1,0 };
        int dy[] = { 0,1 };
        for (int i = 0; i < 2; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr > 9 || nr < 4 || nc < 0 || nc>3)
                continue;
            if (tmp == m[nr][nc])
                return true;
        }
    }

    if (color == 1) {//blue
        int dx[] = { 1,0 };
        int dy[] = { 0,-1 };
        for (int i = 0; i < 2; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr < 0 || nr>3 || nc < 4 || nc>9)
                continue;
            if (tmp == m[nr][nc])
                return true;
        }
    }
    return false;
}
bool erase() {
    bool flag = false;
    for (int i = 6; i < 10; i++) {
        if (m[i][0] > 0 && m[i][1] > 0 && m[i][2] > 0 && m[i][3] > 0) {
            m[i][0] = m[i][1] = m[i][2] = m[i][3] = 0;
            flag = true;
            cnt++;
        }
        if (m[0][i] > 0 && m[1][i] > 0 && m[2][i] > 0 && m[3][i] > 0) {
            m[0][i] = m[1][i] = m[2][i] = m[3][i] = 0;
            flag = true;
            cnt++;
        }
    }
    for (int i = 9; i > 4; i--) {
        for (int j = 0; j < 4; j++) {
            if (m[i][j] > 0) {
                if (isBigBlock(i, j, 0)) {//0 =>green
                    if (m[i][j] == m[i - 1][j]) {
                        int p = i;
                        int t = m[i][j];
                        m[i][j] = m[i - 1][j] = 0;
                        for (; p < 10; p++) {
                            if (p == 9) {
                                m[9][j] = m[8][j] = t;
                            }
                            if (m[p + 1][j] > 0) {
                                m[p][j] = m[p - 1][j] = t;
                                break;
                            }
                        }
                    }
                    else if (m[i][j] == m[i][j + 1]) {
                        int p = i;
                        int t=m[i][j] ;
                        m[i][j] = m[i][j + 1] = 0;
                        for (; p < 10; p++) {
                            if (p == 9) {
                                m[9][j] = m[9][j + 1] = t;
                                break;
                            }
                            if (m[p + 1][j] > 0 || m[p + 1][j + 1] > 0) {
                                m[p][j] = m[p][j + 1] = t;
                                break;
                            }
                        }
                    }
                }
                else {
                    if (j > 0 && m[i][j] == m[i][j - 1])
                        continue;
                    int p = i;
                    int t = m[i][j];
                    m[i][j] = 0;
                    for (; p < 10; p++) {
                        if (p == 9) {
                            m[9][j] = t;
                            break;
                        }
                        if (m[p + 1][j] > 0) {
                            m[p][j] = t;
                            break;
                        }
                    }
                }
            }
        }
    }

    for (int i = 9; i > 4; i--) {
        for (int j = 0; j < 4; j++) {
            if (m[j][i] > 0) {
                if (isBigBlock(j, i, 1)) {//1==>blue
                    if (m[j][i] == m[j][i - 1]) {
                        int p = i;
                        int t = m[j][i];
                        m[j][i] = m[j][i - 1] = 0;
                        for (; p < 10; p++) {
                            if (p == 9) {
                                m[j][9] = m[j][8] = t;
                                break;
                            }
                            if (m[j][p + 1] > 0) {
                                m[j][p] = m[j][p - 1] = t;
                                break;
                            }
                        }
                    }
                    else if (m[j][i] == m[j + 1][i]) {
                        int p = i;
                        int t = m[j][i];
                        m[j][i] = m[j + 1][i] = 0;
                        for (; p < 10; p++) {
                            if (p == 9) {
                                m[j][9] = m[j + 1][9] = t;
                                break;
                            }
                            if (m[j][p + 1] > 0 || m[j + 1][p + 1] > 0) {
                                m[j][p] = m[j + 1][p] = t;
                                break;
                            }
                        }
                    }
                }
                else {
                    if (j > 0 && m[j][i] == m[j - 1][i])
                        continue;
                    int p = i;
                    int t = m[j][i];
                    m[j][i] = 0;
                    for (; p < 10; p++) {
                        if (p == 9) {
                            m[j][9] = t;
                            break;
                        }
                        if (m[j][p + 1] > 0) {
                            m[j][p] = t;
                            break;
                        }
                    }
                }
            }
        }
    }
    return flag;
}
void overflowCheck() {
    //오버플로우된 겨우 당겨주기
    int pivot = -1;
    for (int i = 4; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (m[i][j] > 0) {
                if (pivot == -1)
                    pivot = i;
            }
        }
    }
    int tmp[4][4];
    if (pivot != -1) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                tmp[i][j] = m[i + pivot][j];
            }
        }
        for (int i = 4; i < 6; i++) {
            for (int j = 0; j < 4; j++) {
                m[i][j] = 0;
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                m[i + 6][j] = tmp[i][j];
            }
        }
    }
    pivot = -1;
    for (int i = 4; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (m[j][i] > 0) {
                if (pivot == -1)
                    pivot = i;
            }
        }
    }
    if (pivot != -1) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                tmp[i][j] = m[i][j + pivot];
            }
        }
        for (int i = 4; i < 6; i++) {
            for (int j = 0; j < 4; j++) {
                m[j][i] = 0;
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                m[i][j + 6] = tmp[i][j];
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    while (k--) {
        cin >> t >> r >> c;
        insert(t, r, c);
        while (erase());
        overflowCheck();
    }
    cout << cnt << '\n';
    int green = 0, blue = 0;
    for (int i = 6; i < 10; i++)
        for (int j = 0; j < 4; j++)
            if (m[i][j])
                green++;
    for (int i = 0; i < 4; i++)
        for (int j = 6; j < 10; j++)
            if (m[i][j])
                blue++;
    cout << green + blue;
}