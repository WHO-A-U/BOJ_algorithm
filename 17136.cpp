#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
bool d[10][10];
int cnt=0;
int ans=0x3f3f3f3f;
int paper[]={0,5,5,5,5,5};
bool paint(int r,int c ,int n){
    bool flag=true;
    for(int i=r;i<r+n;i++){
        for(int j=c;j<c+n;j++){
            if(i<0||i>9||j<0||j>9||!d[i][j]){
                flag=false;
                break;
            }
        }
        if(!flag)
            break;
    }
    if(flag)
        for(int i=r;i<r+n;i++){
            for(int j=c;j<c+n;j++){
                    d[i][j]=false;
            }
        } 
    return flag;
}
void go(int r,int c){
    if(r==10&&c==0){
        ans=min(ans,cnt);
        return ;
    }
    if(!d[r][c]){
        int nc = c+1;
        int nr = r+(nc/10);
        nc%=10;
        go(nr,nc);
        return ;
    }
    for(int i=1;i<=5;i++){
        if(paper[i]>0&&paint(r,c,i)){
            paper[i]--;
            cnt++;
            int nc = c+i;
            int nr = r+(nc/10);
            nc%=10;
            go(nr,nc);
            for(int row =r;row<r+i;row++){
                for(int col = c;col<c+i;col++){
                    d[row][col]=true;
                }
            }
            paper[i]++;
            cnt--;
        }
        else{
            if(paper[i]>0)
                break;
        }
    }
    return ;
}
int main(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>d[i][j];
        }
    }
    go(0,0);
    cout<<(ans==0x3f3f3f3f?-1:ans);
}