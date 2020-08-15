#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> dice(10);
vector<int> m[42];
vector<int> who;
int d[5];
int tmp=0,ans=0;
int point[]={0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,13,16,19,25,22,24,28,27,26,30,35,0,0};
void init(){
    for(int i=0;i<=19;i++){
        m[i].push_back(i+1);
    }
    m[5].push_back(21);
    for(int i=21;i<24;i++){
        m[i].push_back(i+1);
    }
    m[10].push_back(25);
    m[25].push_back(26);
    m[26].push_back(24);
    m[15].push_back(27);
    for(int i=27;i<29;i++){
        m[i].push_back(i+1);
    }
    m[29].push_back(24);
    m[24].push_back(30);
    m[30].push_back(31);
    m[31].push_back(20);
    m[20].push_back(32);
}
bool move(int whos,int num){
    int curPos = d[whos];
    if(curPos>=32){
        return true;
    }

    if(m[curPos].size()==2){
        curPos=m[curPos][1];
    }else{
        curPos=m[curPos][0];
    }
    if(curPos>=32){
        d[whos]=curPos;
        return true;
    }
    if(num==1)
        for(int i=1;i<=4;i++){
            if(curPos==d[i])
                return false;
        }
    num--;
    while(num>0){
        num--;
        curPos=m[curPos][0];
        if(curPos>=32){
            d[whos]=32;
            return true;
        }
    }
    for(int i=1;i<=4;i++){
        if(curPos==d[i])
            return false;
    }
    d[whos]=curPos;
    tmp+=point[curPos];
    return true;
}
bool excute(){
    memset(d,0,sizeof(d));
    for(int i=0;i<10;i++){
        int curPin = who[i];
        if(!move(who[i],dice[i]))
            return false;
    }
    return true;
}
void go(int n){
    if(n==10){
        tmp=0;
        if(excute()){
            ans=max(ans,tmp);
            // 결과 담기
        }
        return ;
    }
    for(int i=1;i<=4;i++){
        who.push_back(i);
        go(n+1);
        who.pop_back();
    }
}
int main(){
    for(int i=0;i<10;i++){
        cin>>dice[i];
    }
    init();
    go(0);
    cout<<ans;
}