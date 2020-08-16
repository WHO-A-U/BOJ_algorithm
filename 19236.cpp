#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int origin[4][4][2]; // row col 에 대하여 [0] ==> 번호  [1]==> 방향
vector<pair<pair<int,int>,int>> fish(17);
int ans=0;
// ↑, ↖, ←, ↙, ↓, ↘, →, ↗ 
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,-1,-1,-1,0,1,1,1};
void go(int nrow,int ncol,int score,int map[4][4][2],vector<pair<pair<int,int>,int>> fishs){
    // cout<<"!\n";
    int tmpMap[4][4][2];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<2;k++){
                tmpMap[i][j][k]=map[i][j][k];
            }
        }
    }
    auto fishtmp = fishs;
    int DeletedFishNum = tmpMap[nrow][ncol][0];
    score+=DeletedFishNum;
    int nextSharkDir = tmpMap[nrow][ncol][1];
    tmpMap[nrow][ncol][0]=-2;
    fishtmp[DeletedFishNum]={{-1,-1},-1};
    for(int i=1;i<=16;i++){ //물고기 이동
        if(fishtmp[i].second>=0){
            int cr = fishtmp[i].first.first;
            int cc = fishtmp[i].first.second;
            int dr = fishtmp[i].second;
            for(int j=0;j<8;j++){
                int ndir = (dr+j)%8;
                int nr = cr+dx[ndir];
                int nc=cc+dy[ndir];
                if(nr>=0&&nr<4&&nc>=0&&nc<4&&tmpMap[nr][nc][0]>=0){
                    int tmpNum =tmpMap[nr][nc][0];
                    int tmpDir =tmpMap[nr][nc][1];
                    tmpMap[nr][nc][0]=i;
                    tmpMap[nr][nc][1]=ndir;
                    tmpMap[cr][cc][0]=tmpNum;
                    tmpMap[cr][cc][1]=tmpDir;
                    fishtmp[i]={{nr,nc},ndir}; //이동하려는 물고기
                    fishtmp[tmpNum]={{cr,cc},tmpDir}; //이동하려는 그 위치에 이미 있는 물고기  //둘이 swap 하는 상황
                    break;
                }
            }

        }
    }
    tmpMap[nrow][ncol][0]=0;
    int flag=false;
    int nr = nrow,nc = ncol;
    while(1){
        nr+=dx[nextSharkDir];
        nc+=dy[nextSharkDir];
        if(nr<0||nr>=4||nc<0||nc>=4)
            break;
        if(tmpMap[nr][nc][0]>0){
            flag=true;
            go(nr,nc,score,tmpMap,fishtmp);
        }
    }
    if(!flag){
        ans=max(ans,score);
    } 
}
int main(){
    int a,b;
    fish[0]={{0,0},0};
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>a>>b;
            origin[i][j][0]=a;
            origin[i][j][1]=b-1;
            fish[a]={{i,j},b-1};
        }
    }
    go(0,0,0,origin,fish);
    cout<<ans;
}