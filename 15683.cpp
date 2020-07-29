#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int row,col;
int Origin[9][9];
int minS=0x3f3f3f;
vector<pair<pair<int,int>,int>> Cam;//state row,col / cam number
vector<int> dir; //dir 0:up 1:right : 2:down  3:left;
int D[9][9];
void sight (int cr,int cc,int dir){
    if(dir==0)cr++;
    if(dir==1)cc++;
    if(dir==2)cr--;
    if(dir==3)cc--;

    while(D[cr][cc]!=6 && cr>=1 && cr<=row && cc >=1 && cc <= col){
        D[cr][cc]=-1;
        if(dir==0)cr++;
        if(dir==1)cc++;
        if(dir==2)cr--;
        if(dir==3)cc--;
    }
}
void f1(int cr,int cc,int dir){
    sight(cr,cc,dir);
}
void f2(int cr,int cc,int dir){
    sight(cr,cc,dir);
    sight(cr,cc,(dir+2)%4);
}
void f3(int cr,int cc,int dir){
    sight(cr,cc,dir);
    sight(cr,cc,(dir+1)%4);
}
void f4(int cr,int cc,int dir){
    sight(cr,cc,dir);
    sight(cr,cc,(dir+1)%4);
    sight(cr,cc,(dir+2)%4);
}
void f5(int cr,int cc,int dir){
    sight(cr,cc,0);
    sight(cr,cc,1);
    sight(cr,cc,2);
    sight(cr,cc,3);
}
void excute(){
    for(int i=1;i<=row;i++)
        for(int j=1;j<=col;j++)
        {
            D[i][j]=Origin[i][j];
        }
    for(int i=0;i<Cam.size();i++)
    {
        int cr=Cam[i].first.first;
        int cc=Cam[i].first.second;
        int Camnumber = Cam[i].second;
        if(Camnumber==1)f1(cr,cc,dir[i]);
        if(Camnumber==2)f2(cr,cc,dir[i]);
        if(Camnumber==3)f3(cr,cc,dir[i]);
        if(Camnumber==4)f4(cr,cc,dir[i]);
        if(Camnumber==5)f5(cr,cc,dir[i]);
    }
    int space = 0;
    for(int i=1;i<=row;i++)
        for(int j=1;j<=col;j++)
        {   
            if(D[i][j]==0)
                space++;
        }
    minS=min(minS,space);
}
void go(int n){
    if(n==Cam.size()){
        excute();
        return ;
    }
    for(int i=0;i<4;i++){
        go(n+1);
        if(Cam[n].second==5||(Cam[n].second==2 && i==1))
            break;
        dir[n]++;
    }
    dir[n]=0;
}
int main(){
    cin>>row>>col;
    for(int i=1;i<=row;i++)
        for(int j=1;j<=col;j++){
            cin>>Origin[i][j];
            if(Origin[i][j]>=1&&Origin[i][j]<=5){
                Cam.push_back({{i,j},Origin[i][j]});
                dir.push_back(0);
            }
        }
    go(0);
    cout<<minS;
}