#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
using namespace std;
vector<int> speed;
vector<int> volume;
vector<int> direction; //1up 2down 3right 4left
vector<pair<int,int>>position;
int Ocean[101][101];
int tmp[101][101];
bool live[10001];
int row,col,m;
void sharkmove(int sharknum){
    int s=speed[sharknum];
    int v=volume[sharknum];
    int dir=direction[sharknum];
    int len;
    if(dir==1||dir==2)
        len=row;
    else
        len=col;
    int rem = s%((len-1)*2);
    int currow = position[sharknum].first;
    int curcol = position[sharknum].second;
    while(rem>0)
    {
        if(dir==1&&currow==1)
            dir=2;
        else if(dir==2&&currow==row)
            dir=1;
        else if(dir==3&&curcol==col)
            dir=4;
        else if(dir==4&&curcol==1)
            dir=3;
        if(dir==1)currow--;
        if(dir==2)currow++;
        if(dir==3)curcol++;
        if(dir==4)curcol--;
        rem--;
    }
    direction[sharknum]=dir;
    position[sharknum]={currow,curcol};
    if(tmp[currow][curcol]==-1){
        tmp[currow][curcol]=sharknum;
    }
    else{
        if(volume[sharknum]>volume[tmp[currow][curcol]])
        {
            live[tmp[currow][curcol]]=false;
            tmp[currow][curcol]=sharknum;
        }
        else
        {
            live[sharknum]=false;
        }
        
    }
    
    
}
void nextStage(){
    memset(tmp,-1,sizeof(tmp));
    for(int i=0;i<m;i++){
        if(live[i]==true)
            sharkmove(i);
    }
    memset(Ocean,-1,sizeof(Ocean));
    for(int i=1;i<=row;i++)
        for(int j=1;j<=col;j++)
        {
            Ocean[i][j]=tmp[i][j];
        }
    
    // for(int i=1;i<=row;i++)
    // {
    //     for(int j=1;j<=col;j++)
    //     {
    //         printf("%d ",Ocean[i][j]);
    //     }
    //     cout<<endl;
    // }
    //     cout<<endl;
    

}
int getScore(int curcol){
    for(int i=1;i<=row;i++)
    {
        if(Ocean[i][curcol]>-1){
            live[Ocean[i][curcol]]=false;
            int s = volume[Ocean[i][curcol]];
            Ocean[i][curcol]=-1;
            return s; 
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>row>>col>>m;
    memset(Ocean,-1,sizeof(Ocean));
    for(int i=0;i<m;i++)
    {
        int r,c,s,d,z;
        cin>>r>>c>>s>>d>>z;
        speed.push_back(s);
        volume.push_back(z);
        direction.push_back(d);
        position.push_back({r,c});
        live[i]=true;
        Ocean[r][c]=i;
    }
    // for(int i=1;i<=row;i++)
    // {
    //     for(int j=1;j<=col;j++)
    //     {
    //         printf("%2d ",Ocean[i][j]);
    //     }
    //     cout<<endl;
    // }
    //     cout<<endl;
    int ans=0;
    for(int i=1;i<=col;i++)
    {
        ans+=getScore(i);
        nextStage();
    }
    cout<<ans;
}