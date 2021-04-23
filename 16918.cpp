#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int,int>;
int dx[] ={1,-1,0,0};
int dy[] ={0,0,1,-1};
int n,m,t;
char grid[201][201];
void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j];
        }
        cout<<"\n";
    }
}
void reverse(){
    vvb chk(n,vb(m,false));
    queue<pii> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='O'){
                chk[i][j]=true;
                for(int k=0;k<4;k++){
                    int nr = i+dx[k];
                    int nc = j+dy[k];
                    if(nr>=0&&nr<n&&nc>=0&&nc<m){
                        chk[nr][nc]=true;
                    }
                }
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(chk[i][j])
                grid[i][j] = '.';
            else
                grid[i][j] = 'O';
            
        }
    }
}
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin>>n>>m>>t;
    for(int i=0;i<n;i++){
        cin>>str;
        for(int j=0;j<m;j++){
            grid[i][j]= str[j]; 
        }
    }
    
    if(t>1){
        if(t%2==0){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    grid[i][j]='O';
                }
            }
        }else{
            if(((t-1)/2)%2==1){
                reverse();
            }else{
                reverse();
                reverse();
            }
        }
    }

    print();
    
    
}