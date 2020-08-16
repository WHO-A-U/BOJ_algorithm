#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
//  1, 2, 3, 4는 각각 위, 아래, 왼쪽, 오른쪽
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
pair<int,int> map[21][21];
int sharksDir[401];
pair<int,int> sharksPos[401];
vector<int> sharksR[21][21];
int cnt,n,m,k,x;
vector<vector<vector<int>>> sharksPriority;
void spreadSmell(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j].first!=-1){
                int tmpk=map[i][j].second;
                tmpk--;
                if(tmpk==0)
                    map[i][j]={-1,0};
                else 
                    map[i][j]={map[i][j].first,tmpk};
            }
        }
    }
    for(int i=0;i<m;i++){
        int cr = sharksPos[i].first;
        int cc = sharksPos[i].second;
        if(cr==-1&&cc==-1)
            continue;
        map[cr][cc]={i,k};
    }
}
void sharksMove(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sharksR[i][j].clear();
        }
    }
    for(int i=0;i<m;i++){
        int cr = sharksPos[i].first;
        int cc = sharksPos[i].second;
        if(cr==-1&&cc==-1)
            continue;
        int dir = sharksDir[i];
        bool flag=false;
        for(int j=0;j<4;j++){
            int ndir = sharksPriority[i][dir][j];
            int nr = cr+dx[ndir];
            int nc = cc+dy[ndir];
            if(nr>=0&&nr<n&&nc>=0&&nc<n&&(map[nr][nc].first==-1)){
                sharksDir[i]=ndir;
                sharksPos[i]={nr,nc};
                sharksR[nr][nc].push_back(i);
                flag=true;
                break;
            }
        }
        if(!flag){
            for(int j=0;j<4;j++){
                int ndir = sharksPriority[i][dir][j];
                int nr = cr+dx[ndir];
                int nc = cc+dy[ndir];
                if(nr>=0&&nr<n&&nc>=0&&nc<n&&(map[nr][nc].first==i)){
                    sharksDir[i]=ndir;
                    sharksPos[i]={nr,nc};
                    sharksR[nr][nc].push_back(i);
                    break;
                }
            }
        }
    }
}
void sharksRemain(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sort(sharksR[i][j].begin(),sharksR[i][j].end());
            for(int k=0;k<sharksR[i][j].size();k++){
                if(k>0){
                    sharksPos[sharksR[i][j][k]]={-1,-1};
                }
            }
            if(sharksR[i][j].size()>1){
                cnt=cnt-sharksR[i][j].size()+1;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    cnt=m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>x;
            map[i][j]={-1,0};
            if(x!=0){
                sharksPos[x-1]={i,j};
            }
        }
    }
    for(int i=0;i<m;i++){
        cin>>x;
        sharksDir[i]=x-1;
    }
    for(int i=0;i<m;i++){
        vector<vector<int>> tmps;
        for(int j=0;j<4;j++){
            vector<int> tmp;
            for(int k=0;k<4;k++){
                cin>>x;
                tmp.push_back(x-1);
            }
            tmps.push_back(tmp);
        }
        sharksPriority.push_back(tmps);   
    }
    int z=1;
    for(;z<=1000;z++){
        spreadSmell();
        sharksMove();
        sharksRemain();
        if(cnt==1)
            break;
    }
    if(cnt!=1){
        cout<<"-1";
    }
    else{
        cout<<z;
    }
}