#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
//  →, ←, ↑, ↓
// 0  1  2  3
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int spot[13][13];
stack<pair<int,int>> d[13][13]; //pin num , direction
stack<pair<int,int>> tmp;
queue<pair<int,int>> tq;
vector<pair<pair<int,int>,int>> horse; //row col dir
int n,m;
int opposite(int a){
    if(a==0)return 1;
    if(a==1)return 0;
    if(a==2)return 3;
    return 2;
}
bool containUntil(int r,int c,int num){
    while(1){
        tmp.push(d[r][c].top());
        d[r][c].pop();
        if(tmp.top().first==num)
            break;
    }
    if(tmp.size()>=4)  
        return false;
    return true;
}
bool paste(int r,int c){
    while(!tmp.empty()){
        d[r][c].push(tmp.top());
        int num = tmp.top().first;
        horse[num]={{r,c},horse[num].second};
        tmp.pop();
    }
    if(d[r][c].size()>=4)
        return false;
    return true;
}
bool containUntilR(int r,int c,int num,int nr,int nc){
    while(1){
        tq.push(d[r][c].top());
        d[r][c].pop();
        if(tq.back().first==num)
            break;
    }
    while(!d[nr][nc].empty()){
        tmp.push(d[nr][nc].top());
        d[nr][nc].pop();
    }
    if(tq.size()+tmp.size()>=4)  
        return false;
    return true;
}
bool pasteR(int r,int c){
    while(!tmp.empty()){
        d[r][c].push(tmp.top());
        tmp.pop();
    }
    while(!tq.empty()){
        d[r][c].push(tq.front());
        int num = tq.front().first;
        horse[num]={{r,c},horse[num].second};
        tq.pop();
    }
    if(d[r][c].size()>=4)
        return false;
    return true;
}
bool move(int num){
    int cr = horse[num].first.first;
    int cc = horse[num].first.second;
    int cd = horse[num].second;
    int nr = cr+dx[cd];
    int nc = cc+dy[cd];
    if((nr<1||nr>n||nc<1||nc>n)||spot[nr][nc]==2){
        cd = opposite(cd);
        nr = cr+dx[cd];
        nc = cc+dy[cd];
        horse[num]={{cr,cc},cd};
    }
    int color=spot[nr][nc];
    if(color==2||(nr<1||nr>n||nc<1||nc>n))
        return true;
    if(color==0)
        if(!(d[nr][nc].size()<4&&containUntil(cr,cc,num)&&paste(nr,nc)))
            return false;

    if(color==1)
        if(!(d[nr][nc].size()<4&&containUntilR(cr,cc,num,nr,nc)&&pasteR(nr,nc)))
            return false;
    return true;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>spot[i][j];
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        d[a][b].push({i,c-1});
        horse.push_back({{a,b},c-1}); 
    }
    for(int z=1;z<=1000;z++){
        for(int h=0;h<horse.size();h++){
            if(!move(h)){
                cout<<z;
                return 0;
            }
        }
    }
    cout<<-1;
    
}