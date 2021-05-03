#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int n,m,r,x;
vvi answer;
void oper1(){
    reverse(all(answer));
}
void oper2(){
    for(auto &arr:answer){
        reverse(all(arr));
    }
}
void oper3(){
    int row = answer.size();
    int col = answer[0].size();
    vvi ret(col,vi(row));
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            ret[i][j] = answer[row-1-j][i];
        }
    }
    answer.clear();
    answer = ret;
}
void oper4(){
    for(int i=0;i<3;i++){
        oper3();
    }
}
void oper5(){
    int rh = answer.size()/2;
    int ch = answer[0].size()/2;

    vvi LU(rh,vi(ch));

    for(int i=0;i<rh;i++){
        for(int j=0;j<ch;j++){
            LU[i][j] = answer[i][j];
        }
    }

    pii p[] = {{0,0},{rh,0},{rh,ch},{0,ch}};
    for(int k=1;k<4;k++){
        for(int i=0;i<rh;i++){
            for(int j=0;j<ch;j++){
                answer[p[k-1].ft+i][p[k-1].sd+j] = answer[p[k].ft+i][p[k].sd+j];
            }
        }
    }
    for(int i=0;i<rh;i++){
        for(int j=0;j<ch;j++){
            answer[i][ch+j] = LU[i][j];
        }
    }
}
void oper6(){
    for(int i=0;i<3;i++){
        oper5();
    }
}
void (*fp[6])() = {oper1,oper2,oper3,oper4,oper5,oper6};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>r;
    for(int i=0;i<n;i++){
        vi arr(m);
        for(int j=0;j<m;j++)
            cin>>arr[j];
        answer.push_back(arr);
    }

    while(r--){
        cin>>x;
        (fp[x-1])();
    }
    
    int r = answer.size();
    int c = answer[0].size();

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            cout<<answer[i][j]<<" ";
        cout<<"\n";
    }
}