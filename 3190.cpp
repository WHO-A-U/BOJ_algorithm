#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
int n, k, l, time = 0;
int d[101][101]; // 0 space   1  snake   2 apple
vector<pair<int, char>> v;
deque<pair<int, int>> snake;
int currentdir = 1, pivot = 0;
bool go() { //dir 0 : up // 1 : right// 2 : down // 3 : left
    if (v[pivot].first == time && pivot < v.size()) {
            if (v[pivot].second == 'L')
                currentdir = (currentdir - 1+4) % 4;
            else
                currentdir = (currentdir + 1+4) % 4;
            pivot++;
        }
    time++;
    int tr = snake.front().first;
    int tc = snake.front().second;
    int hr = snake.back().first;
    int hc = snake.back().second;
    if (currentdir == 0)hr--;
    if (currentdir == 1)hc++;
    if (currentdir == 2)hr++;
    if (currentdir == 3)hc--;
    if (d[hr][hc] == 0){
        snake.pop_front();
        d[tr][tc] = 0;
    }
    if (d[hr][hc] == 1||hr<1||hr>n||hc<1||hc>n)
        return false;
    snake.push_back({ hr,hc });
    d[hr][hc] = 1;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    int r, c;
    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        d[r][c] = 2; // apple position
    }
    d[1][1] = 1;
    snake.push_back({ 1,1 });
    cin >> l;
    char z;
    for (int i = 0; i < l; i++) {
        cin >> r >> z;
        v.push_back({ r,z });
    }
    while (go());
    cout << time;
}