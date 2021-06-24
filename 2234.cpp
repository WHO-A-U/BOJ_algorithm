#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
int d[55][55];
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
/*
서쪽에 벽이 있을 때는 1을, 
북쪽에 벽이 있을 때는 2를, 
\동쪽에 벽이 있을 때는 4를, 
남쪽에 벽이 있을 때는 8을 더한 값이 주어진다. 
*/
bool chk[55][55];
int n,m;
bool isValid(int r , int c){
    return r>=0&&r<n && c>=0&&c<m;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int ans1=0,ans2=0,ans3=0;
    cin>>m>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>d[i][j];
        }
    }

    memset(chk,false,sizeof(chk));


    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!chk[i][j]){
                int size=1;
                ans1++;
                chk[i][j]=true;
                q.push({i,j});
                while(!q.empty()){
                    int cr = q.front().first;
                    int cc = q.front().second;
                    
                    int cur = d[cr][cc];
                    q.pop();
                    for(int k=0;k<4;k++){
                        if((cur & (1<<k)) == 0){
                           int nr = cr+dx[k];
                           int nc = cc+dy[k];
                           if(!chk[nr][nc] && isValid(nr,nc)){
                            chk[nr][nc]=true;
                            size++;
                            q.push({nr,nc}); 
                           }
                        }
                    }
                }
                ans2 = max(ans2,size);
            }
        }
    }

    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int &cur = d[i][j];
            for(int k=0;k<4;k++){
                if( (cur & (1<<k)) !=0){
                    cur-=(1<<k);

                    int size=1;
                    memset(chk,false,sizeof(chk));
                    q.push({i,j});
                    chk[i][j]=true;
                    while(!q.empty()){
                        int cr = q.front().first;
                        int cc = q.front().second;
                        q.pop();
                        int now = d[cr][cc];
                        for(int z=0;z<4;z++){
                            if((now & (1<<z)) == 0){
                                int nr = cr+dx[z];
                                int nc = cc+dy[z];

                                if(!chk[nr][nc] && isValid(nr,nc)){
                                    q.push({nr,nc});
                                    chk[nr][nc]=true;
                                    size++;

                                }
                            }
                        }
                    }
                    ans3 = max(ans3,size);
                    cur+=(1<<k);
                }
            }
        }
    }

    cout<<ans1<<"\n"<<ans2<<"\n"<<ans3;

    
    
    
    
}