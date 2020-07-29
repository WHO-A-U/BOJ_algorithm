#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int D[51][51];
int tmp[51][51];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int r,c,t,p=-1;
int go(int cr,int cc,int n){
    int waste=0;
    for(int i=0;i<4;i++){
        int nr=cr+dx[i];
        int nc=cc+dy[i];
        if(nr>=1&&nr<=r&&nc<=c&&nc>=1&&D[nr][nc]!=-1){
            tmp[nr][nc]+=n;
            waste+=n;
        }
    }
    return waste;
}
void spread(){
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            tmp[i][j]=0;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++){
            if(D[i][j]>=5)
                tmp[i][j]+=(D[i][j]-go(i,j,D[i][j]/5));
            else
                tmp[i][j]+=D[i][j];
        }
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            if(D[i][j]!=-1){
                D[i][j]=tmp[i][j];
            }

}
int popInt(queue<int> &q){
    int x= q.front();
    q.pop();
    return x;
}
void airFresh(){
    queue<int> q;
    for(int i=2;i<=c;i++)q.push(D[p][i]);
    for(int i=p-1;i>=1;i--)q.push(D[i][c]);
    for(int i=c-1;i>=1;i--)q.push(D[1][i]);
    for(int i=2;i<p;i++)q.push(D[i][1]);
    D[p][2]=0;
    for(int i=3;i<=c;i++)D[p][i]=popInt(q);
    for(int i=p-1;i>=1;i--)D[i][c]=popInt(q);
    for(int i=c-1;i>=1;i--)D[1][i]=popInt(q);
    for(int i=2;i<p;i++)D[i][1]=popInt(q);
    q.pop();
    for(int i=2;i<=c;i++)q.push(D[p+1][i]);
    for(int i=p+2;i<=r;i++)q.push(D[i][c]);
    for(int i=c-1;i>=1;i--)q.push(D[r][i]);
    for(int i=r-1;i>=p+2;i--)q.push(D[i][1]);
    D[p+1][2]=0;
    for(int i=3;i<=c;i++)D[p+1][i]=popInt(q);
    for(int i=p+2;i<=r;i++)D[i][c]=popInt(q);
    for(int i=c-1;i>=1;i--)D[r][i]=popInt(q);
    for(int i=r-1;i>=p+2;i--)D[i][1]=popInt(q);
    q.pop();
}
int getScore(){
    int sum=0;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            if(D[i][j]!=-1)
                sum+=D[i][j];
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>r>>c>>t;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>D[i][j];
            if(D[i][j]==-1&&p==-1)
                p=i;
        }
    }
    while(t--){
        spread();
        airFresh();
    }
    cout<<getScore();
}