#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,k;
int seed[11][11];//현재양분
int d[11][11];//추가양분
int spread[11][11];
vector <int> tree[11][11];
vector <int> deadTree[11][11];
int dx[]={-1,0,1,-1,1,-1,0,1};
int dy[]={-1,-1,-1,0,0,1,1,1};
void spring(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            vector <int> tmp;
            sort(tree[i][j].begin(),tree[i][j].end());
            for(int z=0;z<tree[i][j].size();z++){
                if(tree[i][j][z]<=seed[i][j]){
                    tmp.push_back(tree[i][j][z]+1);
                    if((tree[i][j][z]+1)%5==0)
                        spread[i][j]++;
                    seed[i][j]-=tree[i][j][z];
                }
                else{
                    deadTree[i][j].push_back(tree[i][j][z]);
                }
            }
            tree[i][j].clear();
            for(int z=0;z<tmp.size();z++){
                tree[i][j].push_back(tmp[z]);
            }
        }
    }
}
void summer(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int z=0;z<deadTree[i][j].size();z++){
                seed[i][j]+=(deadTree[i][j][z]/2);
            }
            deadTree[i][j].clear();
        }
    }
}
void fall(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int z=0;z<8;z++){
                int row = i+dx[z];
                int col = j+dy[z];
                if(row>=1&&row<=n&&col>=1&&col<=n){  
                    for(int q=0;q<spread[i][j];q++){
                      tree[row][col].push_back(1);
                     }
                 }
              }
            spread[i][j]=0;
        }
    }
}
void winter(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            seed[i][j]+=d[i][j];
        }
    }
}
void year(){
    spring();
    summer();
    fall();
    winter();
}
int entry(){
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans+=tree[i][j].size();
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>d[i][j];
            seed[i][j]=5;
        }
    }
    int r,c,s;
    for(int i=0;i<m;i++){
        cin>>r>>c>>s;
        tree[r][c].push_back(s);
    }
    while(k--)year();
    cout<<entry();
}