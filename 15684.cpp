#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> horizon[31];
int d[31][11];
vector<pair<int,int>> tmp;
vector<pair<int,int>> emptys;
bool flag = false;
int n,m,h;
bool verify(){
    for(int i=1;i<=n;i++){
        int cur = i;
        for(int j=1;j<=h;j++){
            if(d[j][cur-1]==1){
                cur--;
            }
            else if(d[j][cur]==1){
                cur++;
            }
        }
        if(cur!=i)
            return false;
    }
    return true;
}
void go(int cnt,int row,int col){
    int r = row;
    int c = col;
    if(cnt==0){
        if(verify()){
            flag=true;
        }
        return ;
    }
    if(row>h)
        return ;
    if(d[row][col]==0&&d[row][col-1]==0&&d[row][col+1]==0){
        d[row][col]=1;
        col++;
        if(col>=n){
            row++;
            col=1;
        }
        go(cnt-1,row,col);
        d[r][c]=0;
    }
    c++;
    if(c>=n){
        r++;
        c=1;
    }
    go(cnt,r,c);
    return ;
}
int main(){
    cin>>n>>m>>h;
    for(int i=0;i<m;i++){
        int depth,num;
        cin>>depth>>num;
        d[depth][num]=1;
    }
    for(int i=0;i<4;i++){
        flag=false;
        go(i,1,1);
        if(flag){
            cout<<i;
            return 0;
        }
    }
    cout<<"-1";
}