#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,1,-1,1,-1};
char C[]={'A','B','C','D','E','F','G','H'};
char R[]={'8','7','6','5','4','3','2','1'};
int getOperCode(string op){
    if(op=="R")return 0;
    if(op=="L")return 1;
    if(op=="B")return 2;
    if(op=="T")return 3;
    if(op=="RT")return 4;
    if(op=="LT")return 5;
    if(op=="RB")return 6;
    if(op=="LB")return 7;
}
int getCol(char x){
    for(int i=0;i<8;i++)
        if(C[i]==x)
            return i;
}
int getRow(char x){
    for(int i=0;i<8;i++)
        if(R[i]==x)
            return i;
}
bool isPossible(int r,int c){
    if(r>=0&&r<8&&c>=0&&c<8)return true;
    return false;
}
int main(){
    string king,rock,numStr;
    cin>>king>>rock>>numStr;
    int kr=getRow(king[1]);
    int kc=getCol(king[0]);
    int rr=getRow(rock[1]);
    int rc=getCol(rock[0]);
    int num = stoi(numStr);
    string oper;
    for(int i=0;i<num;i++){
        cin>>oper;
        int op = getOperCode(oper);
        int nr = kr+dx[op];
        int nc = kc+dy[op];
        if(!isPossible(nr,nc))continue;
        if(nr==rr&&nc==rc){
            int Nrr = rr+dx[op];
            int Nrc = rc+dy[op];
            if(!isPossible(Nrr,Nrc))continue;
            rr = Nrr;
            rc = Nrc;
        }
        kr = nr;
        kc = nc;
    }
    cout<<C[kc]<<R[kr]<<'\n';
    cout<<C[rc]<<R[rr];
    
    return 0;
}