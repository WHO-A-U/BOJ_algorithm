#include<iostream>
#include<vector>
using namespace std;
char d[10][10];
bool vr[10][10];
bool vc[10][10];
bool t[4][4][10];
int flag=0;
void go (int cnt){
    if(cnt==81){
        //backtracking end point
        for(int i=1;i<=9;i++){
            for(int j=1;j<=9;j++){
                cout<<d[i][j];
            }
            cout<<'\n';
        }
        flag=1;
        return ;
    }
    int r=(cnt/9)+1;
    int c=cnt%9+1;
    int tr=(r-1)/3+1;
    int tc=(c-1)/3+1;
    if(d[r][c]!='0')
        go(cnt+1);
    else{
        for(int i=1;i<=9;i++){
            if(vr[r][i]==false && vc[c][i]==false&&t[tr][tc][i]==false){
                d[r][c]=(char)(i+'0');
                vr[r][i]=vc[c][i]=t[tr][tc][i]=true;
                go(cnt+1);
                if(flag==1)
                    return ;
                vr[r][i]=vc[c][i]=t[tr][tc][i]=false;
                d[r][c]='0';
            }
        }
    }
    return ;
}
int main(){
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            cin>>d[i][j];
            vr[i][d[i][j]-'0']=true;
            vc[j][d[i][j]-'0']=true;
            t[(i-1)/3+1][(j-1)/3+1][d[i][j]-'0']=true;
        }
    }
    go(0);
    
}