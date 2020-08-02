#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
vector<char> words[300001];
bool wordscheck[300001];
string wordsString[300001];
char board[4][4];
vector<int> tmp;
bool visit[4][4];
int dx[] = { 1,1,1,0,0,-1,-1,-1 };
int dy[] = { 1,0,-1,1,-1,1,0,-1 };
int point[] = { 0,0,0,1,1,2,3,5,11 };
int flag = 0;
int go(int row, int col, int wordIdx, int dep) {
    if (dep == words[wordIdx].size() - 1)
    {
        //찾았다
        flag = 1;
        return 0;
    }
    visit[row][col] = true;
    for (int i = 0; i < 8; i++) {
        int nr = row + dx[i];
        int nc = col + dy[i];
        if (nr >= 0 && nr < 4 && nc >= 0 && nc < 4 && visit[nr][nc] == false && board[nr][nc] == words[wordIdx][dep + 1]) {
            go(nr, nc, wordIdx, dep + 1);
            if (flag == 1)
                return 0;
        }
    }
    visit[row][col] = false;
    return 0;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w;
    string word;
    cin >> w;
    for (int i = 0; i < w; i++) {
        cin >> word;
        wordsString[i] = word;
        for (int j = 0; j < word.length(); j++) {
            words[i].push_back(word[j]);
        }
    }
    int n;
    cin >> n;
    while (n--) {
        for (int i = 0; i < 4; i++) {
            cin >> word;
            for (int j = 0; j < 4; j++) {
                board[i][j] = word[j];
            }
        }
        long long maxval = 0;
        int maxlen = 0;
        int maxidx;
        int cnt = 0;
        vector<string> maxlenword;
        memset(wordscheck, false, sizeof(wordscheck));
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < w; k++) {
                    if (wordscheck[k] == true)
                        continue;
                    flag = 0;
                    memset(visit, false, sizeof(visit));
                    if(board[i][j]==words[k][0])
                        go(i, j, k, 0);
                    if (flag == 1) {
                        
                        wordscheck[k] = true;

                        cnt++;
                        int len = words[k].size();
                        if (len > maxlen) {
                            maxlen = len;
                            maxidx = k;
                            maxlenword.clear();
                        }
                        if(len==maxlen)
                            maxlenword.push_back(wordsString[k]);
                        int p = point[len];
                        maxval += p;
                    }
                }
            }
        }
        sort(maxlenword.begin(), maxlenword.end());
        cout << maxval << " " << maxlenword[0];
        cout << " " << cnt << "\n";
    }
}