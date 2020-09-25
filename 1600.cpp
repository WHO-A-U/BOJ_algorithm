#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int d[201][201][31];
int hr[]={2,2,1,1,-1,-1,-2,-2};
int hc[]={1,-1,2,-2,2,-2,1,-1};
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
queue<pair<pair<int,int>,pair<int,int>>> q;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int K,width,height,x;
    cin>>K>>width>>height;
    memset(d,-1,sizeof(d));
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>x;
            if(x==1){
                for(int k=0;k<=K;k++){
                    d[i][j][k]=-2;
                }
            }
        }
    }
    q.push({{0,0},{0,K}});
    //row col dist rest
    d[0][0][K]=0;
    while(!q.empty()){
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int dist = q.front().second.first;
        int rest = q.front().second.second;
        q.pop();
        if(rest>0){
            for(int i=0;i<8;i++){
                int nr = cr+hr[i];
                int nc = cc+hc[i];
                if(nr>=0&&nr<height&&nc>=0&&nc<width){
                    int &ret = d[nr][nc][rest-1];
                    if(ret == -1 || (ret>dist+1)){
                        ret=dist+1;
                        q.push({{nr,nc},{dist+1,rest-1}});
                    }
                }
            }
        }
        for(int i=0;i<4;i++){
            int nr = cr+dx[i];
            int nc = cc+dy[i];
            if(nr>=0&&nr<height&&nc>=0&&nc<width){
                int &ret = d[nr][nc][rest];
                if(ret==-1||(ret>dist+1)){
                    ret=dist+1;
                    q.push({{nr,nc},{dist+1,rest}});
                }
            }
        }
    }
    int minVal=0x3f3f3f3f;
    for(int i=0;i<=K;i++){
        if(minVal>d[height-1][width-1][i]&&d[height-1][width-1][i]>=0){
            minVal=d[height-1][width-1][i];
        }
    }
    if(minVal==0x3f3f3f3f){
        cout<<"-1";
    }else{
        cout<<minVal;
    }
}