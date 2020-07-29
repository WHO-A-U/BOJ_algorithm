#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
int tempCube[6][6][6];
int realFloor[6][6][6];
int visit[6][6][6];
int temp[6][6];
int ans=INF;
int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};
vector<int> order;
void clearCube();
void makeCube();
void rotateCube();
void clockwise(int floor);
void printTempCube();
void bfs(){
    clearCube();
    queue<pair<pair<int,int>,int>> q;
    if(tempCube[1][1][1]==0||tempCube[5][5][5]==0)
        return ;
    q.push({{1,1},1});
    visit[1][1][1]=0;
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int floor=q.front().second;
        int cur=visit[floor][row][col];
        q.pop();
        for(int i=0;i<6;i++)
        {
            int nrow=row+dx[i];
            int ncol=col+dy[i];
            int nfloor=floor+dz[i];
            if(nrow>=1&&nrow<=5&&ncol>=1&&ncol<=5&&nfloor>=1&&nfloor<=5&&tempCube[nfloor][nrow][ncol]==1){
               
                if(visit[nfloor][nrow][ncol]>cur+1){
                    // cout<<"!!!!!!!!\n";
                    visit[nfloor][nrow][ncol]=cur+1;
                    q.push({{nrow,ncol},nfloor});
                }
            }
        }
    }
    // printTempCube();
    if(visit[5][5][5]!=INF){
        ans=min(ans,visit[5][5][5]);
    }
}
void clearCube(){
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            for(int k=1;k<=5;k++)
            {
                visit[i][j][k]=INF;
            }
        }
    }
}
void makeCube() // 위에서부터 a b c d e 순으로 쌓음
{
    for(int i=0;i<order.size();i++)
    {   
        int floor=order[i];
        for(int j=1;j<=5;j++)
        {
            for(int k=1;k<=5;k++)
            {   
                // cout<<" tempCube[i+1][j][k]=realFloor[floor][j][k] "<<tempCube[i+1][j][k]<<" "<<realFloor[floor][j][k]<<'\n';
                tempCube[i+1][j][k]=realFloor[floor][j][k];
            }
        }
    }
  
    rotateCube();
}
void printTempCube(){
     for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            for(int k=1;k<=5;k++){
                cout<<tempCube[i][j][k]<<" ";
            }
            cout<<'\n';
        }
        cout<<"************floor************\n";
    }
    cout<<"visit\n!!!!!!!!!!!!!!!!!!!!!!!!!\n";
     for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            for(int k=1;k<=5;k++){
                cout<<visit[i][j][k]<<" ";
            }
            cout<<'\n';
        }
        cout<<"************floor************\n";
    }
}
void rotateCube(){
    // bfs();
    for(int f1=0;f1<4;f1++)
    {  
        for(int f2=0;f2<4;f2++){
      
            for(int f3=0;f3<4;f3++)
            {   
                for(int f4=0;f4<4;f4++){
                   
                    for(int f5=0;f5<4;f5++)
                    {
                        bfs();
                        clockwise(5);
                    }
                     clockwise(4);
                }
                clockwise(3);
            }
            clockwise(2);
        }
        clockwise(1);
    }
}

void clockwise(int floor){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++)
        {
            temp[i][j]=tempCube[floor][i][j];
        }
    }
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++)
        {
            tempCube[floor][6-j][i]=temp[i][j];
        }
    }
}

int main()
{
    for(int i=1;i<=5;i++)
    {
        order.push_back(i);
        for(int j=1;j<=5;j++)
        {
            for(int k=1;k<=5;k++){
                cin>>realFloor[i][j][k];
            }
        }
    }
    // makeCube(); //test
    while(1){
        makeCube();
        if(!next_permutation(order.begin(),order.end()))
            break;
    }
    
    if(ans==INF){
        ans=-1;
    }
    cout<<ans;
}
