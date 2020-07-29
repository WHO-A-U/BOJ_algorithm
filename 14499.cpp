#include<iostream>
using namespace std;
int d[21][21];
int dice[4],dl,dr;
int n,m,r,c,k,cmd;
void right(){
    int tmp=dice[1];
    dice[1]=dr;
    dr=dice[3];
    dice[3]=dl;
    dl=tmp;
}
void left(){
    int tmp=dice[1];
    dice[1]=dl;
    dl=dice[3];
    dice[3]=dr;
    dr=tmp;
}
void up(){
    int tmp=dice[1];
    dice[1]=dice[0];
    dice[0]=dice[3];
    dice[3]=dice[2];
    dice[2]=tmp;
}
void down(){
    int tmp=dice[1];
    dice[1]=dice[2];
    dice[2]=dice[3];
    dice[3]=dice[0];
    dice[0]=tmp;
}
bool go(int cmd){
    int dr=0,dc=0;
    if(cmd==1)dc++;
    if(cmd==2)dc--;
    if(cmd==3)dr--;
    if(cmd==4)dr++;
    int nr=r+dr;
    int nc=c+dc;
    if(nr>=0&&nr<n&&nc>=0&&nc<m){
        r=nr;
        c=nc;
        if(cmd==1)right();
        if(cmd==2)left();
        if(cmd==3)up();
        if(cmd==4)down();
        return true;
    }
    return false;
}
int main(){
    cin>>n>>m>>r>>c>>k;
    int x;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>d[i][j];
        }
    }
    for(int i=0;i<k;i++){
        cin>>cmd;
        if(go(cmd)){
            if(d[r][c]==0){
                d[r][c]=dice[1];
            }else{
                dice[1]=d[r][c];
                d[r][c]=0;
            }
            cout<<dice[3]<<'\n';
        }
    }
}