#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<set>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;
string d[1001];
int color[1001][1001];
vi colorArr;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
set<int> around;
int h,w;
int getAroundZero(int r , int c){
    around.clear();
    int ret=0;
    for(int i=0;i<4;i++){
        int nr = r+dx[i];
        int nc = c+dy[i];
        if(nr>=0&&nr<h&&nc>=0&&nc<w){
            if(around.find(color[nr][nc])==around.end()){
                around.insert(color[nr][nc]);
                ret+=colorArr[color[nr][nc]];
            }
        }
    }
    return ret+1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>h>>w;
    string s;
    for(int i=0;i<h;i++){
        cin>>s;
        d[i]=s;
    }

    colorArr.push_back(0);

    queue<pii> q;
    int colorCnt=1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(d[i][j]=='0'&&color[i][j]==0){
                int tmpCnt=0;
                q.push({i,j});
                color[i][j]=colorCnt;
                
                while(!q.empty()){
                    tmpCnt++;
                    int cr = q.front().first;
                    int cc = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nr = cr+dx[k];
                        int nc = cc+dy[k];
                        if(nr>=0&&nr<h&&nc>=0&&nc<w){
                            if(d[nr][nc]=='0'&&color[nr][nc]==0){
                                color[nr][nc]=colorCnt;
                                q.push({nr,nc});
                            }
                        }
                    }
                }
                colorArr.push_back(tmpCnt);
                colorCnt++;
            }
        }
    }
    


    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(d[i][j]=='1'){
                cout<<getAroundZero(i,j)%10;
            }else{
                cout<<"0";
            }
        }
        cout<<"\n";
    }

}