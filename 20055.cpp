#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int con[201];
bool v[201];
int n,k,kcnt=0,u=1,d;
vector<int> Robot;
void conMove(){
    u--;
    d--;
    if(u<1)u=2*n;
    if(d<1)d=2*n;
    return ;
}
int nextCon(int cur){
    if(cur+1>2*n)
        return 1;
    return cur+1;
}
void RobotsMove(){
    bool flag;
    for(int i=0;i<Robot.size();i++){
        flag=false;
        if(i==0)flag=true;
        else if(Robot[i-1]!=nextCon(Robot[i]))flag=true;
        if(flag){
            if(con[nextCon(Robot[i])]>0){
                con[nextCon(Robot[i])]--;
                Robot[i]=nextCon(Robot[i]);
            }
        }
    }
}
void checkDownArea(){
    if(Robot.size()>0&&Robot[0]==d){
        Robot.erase(Robot.begin());
    }
    
}
void findZeroCon(){
    for(int i=1;i<=2*n;i++){
        if(con[i]==0&&!v[i]){
            v[i]=true;
            kcnt++;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    d=n;
    for(int i=1;i<=2*n;i++){
        cin>>con[i];
    }
    int ans=0;
    while(k>kcnt){
        ans++;
        conMove();
        checkDownArea();
        RobotsMove();
        checkDownArea();
        if(con[u]>0){
            Robot.push_back(u);
            con[u]--;
        }
        findZeroCon();
    }
    cout<<ans;
}