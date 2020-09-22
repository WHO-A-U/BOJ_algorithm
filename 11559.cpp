#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
char d[12][8];
bool v[12][8];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void gravity(){
    queue<char> q;
    for(int j=0;j<6;j++){
        for(int i=11;i>=0;i--){
            if(d[i][j]!='.'){
                q.push(d[i][j]);
                d[i][j]='.';
            }
        }
        if(q.size()>0){
            int s = q.size();
            for(int i=0;i<s;i++){
                d[11-i][j]=q.front();
                q.pop();
            }
        }
    }
}
int main(){
    string s;
    for(int i=0;i<12;i++){
        cin>>s;
        for(int j=0;j<6;j++){
            d[i][j]=s[j];
        }
    } 
    int cnt=0;
    queue<pair<int,int> > q;
    while(true){
        // cout<<"************************\n";
        // for(int i=0;i<12;i++){
        //     for(int j=0;j<6;j++){
        //         cout<<d[i][j];
        //     }
        //     cout<<"\n";
        // }
        // cout<<"************************\n";
        bool again=false;
        for(int i=0;i<12;i++){
            for(int j=0;j<6;j++){
                if(d[i][j]!='.'){
                    q.push(make_pair(i,j));
                    memset(v,false,sizeof(v));
                    v[i][j]=true;
                    int areacnt=1;
                    while(!q.empty()){
                        int cr = q.front().first;
                        int cc = q.front().second;
                        char cd = d[cr][cc];
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nr = cr +dx[k];
                            int nc = cc +dy[k];
                            if(nr>=0&&nr<12&&nc>=0&&nc<6){
                                if(d[nr][nc]==cd&&!v[nr][nc]){
                                    areacnt++;
                                    v[nr][nc]=true;
                                    q.push(make_pair(nr,nc));
                                }
                            }
                        }
                    }
                    if(areacnt>=4){
                        again=true;
                        char target=d[i][j];
                        q.push(make_pair(i,j));
                        memset(v,false,sizeof(v));
                        v[i][j]=true;
                        d[i][j]='.';
                        while(!q.empty()){
                        int cr = q.front().first;
                        int cc = q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nr = cr +dx[k];
                            int nc = cc +dy[k];
                            if(nr>=0&&nr<12&&nc>=0&&nc<6){
                                if(d[nr][nc]==target&&!v[nr][nc]){
                                    areacnt++;
                                    v[nr][nc]=true;
                                    d[nr][nc]='.';
                                    q.push(make_pair(nr,nc));
                                }
                            }
                        }
                    }
                    }
                }
            }
        }
        if(again){
            cnt++;
            gravity();
        }else{
            break;
        }
    }
    cout<<cnt;
}