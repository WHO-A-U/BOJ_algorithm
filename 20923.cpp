#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<cstring>
#include<algorithm>
using namespace std;
deque<int> a,b,ga,gb;
void stagingA(){
    ga.push_back(a.back());
    a.pop_back();
}
void stagingB(){
    gb.push_back(b.back());
    b.pop_back();
}

void shuffle(deque<int> &mine , deque<int> &first, deque<int> &second){
    while(!first.empty()){
        mine.push_front(first.front());
        first.pop_front();
    }

    while(!second.empty()){
        mine.push_front(second.front());
        second.pop_front();
    }

}
void findRoundWinner(){
    if(!ga.empty()&&!gb.empty()){//su 승리
        if(ga.back()+gb.back()==5){
            shuffle(b,ga,gb);
        }
    }
    if((!ga.empty()&&ga.back()==5)||(!gb.empty()&&gb.back()==5)){
        shuffle(a,gb,ga);
    }
    return ;
}
int isGameOver(){
    if(a.size()==0){
        return 2; //su 이김
    }
    if(b.size()==0){
        return 1;//do 이김
    }
    findRoundWinner();
    return -1;//계속 진행
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,x,y,flag=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        a.push_back(x);
        b.push_back(y);
    }
    for(int j=0;j<m;j++){
        stagingA();
        flag = isGameOver();
        if(flag>=1){
            break;
        }
        j++;
        if(j>=m)break;
        stagingB();
        flag = isGameOver();
        if(flag>=1){
            break;
        }
    }
    if(flag<=0){
        if(a.size()>b.size()){
            flag=1;
        }
        if(a.size()<b.size()){
            flag=2;
        }
        if(a.size()==b.size()){
            flag=0;
        }
    }
    if(flag>0){
        if(flag==1){
            cout<<"do";
        }else{
            cout<<"su";
        }
    }else{
        cout<<"dosu";
    }
    return 0;

}