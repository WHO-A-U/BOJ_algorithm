#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;
int D[21][21];
int Origin[21][21];
int n;
int ans=0;
vector<int> direction;//1 up /2 right/ 3 down/ 4 left
void eval(){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(D[i][j]>ans)
                ans=D[i][j];
        }
    }
}
void reset(){
 for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            D[i][j]=Origin[i][j];
        }
    }
}
void excute(){
    reset();
    for(int i=0;i<direction.size();i++)
    {
        if(direction[i]==1){
            for(int col=1;col<=n;col++)
            {
                deque<int> q;
                bool Merge=false;
                for(int row=1;row<=n;row++)
                {
                    if(D[row][col]!=0){
                        if(!q.empty()&&q.back()==D[row][col]&&Merge){
                            int x=q.back();
                            q.pop_back();
                            q.push_back(x*2);
                            Merge=false;
                        }
                        else{
                            q.push_back(D[row][col]);
                            Merge=true;
                        }
                    }
                }
                for(int row=0;row<n;row++)
                {
                    if(row<q.size())
                        D[row+1][col]=q[row];
                    else
                        D[row+1][col]=0;
                }
                // for(int row=0;row<q.size();row++)
                // {
                //     D[row+1][col]=q[row];
                // }
            }
        }
        if(direction[i]==2){
            for(int row=1;row<=n;row++)
            {
                deque<int> q;
                bool Merge=false;
                for(int col=n;col>=1;col--)
                {
                    if(D[row][col]!=0){
                        if(!q.empty()&&q.back()==D[row][col]&&Merge){
                            int x=q.back();
                            q.pop_back();
                            q.push_back(x*2);
                            Merge=false;
                        }
                        else{
                            q.push_back(D[row][col]);
                            Merge=true;
                        }
                    }
                }
                for(int col=0;col<n;col++)
                {
                    if(col<q.size())
                        D[row][n-col]=q[col];
                    else
                        D[row][n-col]=0;
                }
                // for(int col=0;col<q.size();col++)
                // {
                //     D[row][n-col]=q[col];
                // }
            }
        }
        if(direction[i]==3){
             for(int col=1;col<=n;col++)
            {
                deque<int> q;
                bool Merge=false;
                for(int row=n;row>=1;row--)
                {
                    if(D[row][col]!=0){
                        if(!q.empty()&&q.back()==D[row][col]&&Merge){
                            int x=q.back();
                            q.pop_back();
                            q.push_back(x*2);
                            Merge=false;
                        }
                        else{
                            q.push_back(D[row][col]);
                            Merge=true;
                        }
                    }
                }
                // for(int row=0;row<q.size();row++)
                // {
                //     D[n-row][col]=q[row];
                // }
                for(int row=0;row<n;row++)
                {
                    if(row<q.size())
                        D[n-row][col]=q[row];
                    else
                        D[n-row][col]=0;
                }
            }
        }
        if(direction[i]==4){
              for(int row=1;row<=n;row++)
            {
                deque<int> q;
                bool Merge=false;
                for(int col=1;col<=n;col++)
                {
                    if(D[row][col]!=0){
                        if(!q.empty()&&q.back()==D[row][col]&&Merge){
                            int x=q.back();
                            q.pop_back();
                            q.push_back(x*2);
                            Merge=false;
                        }
                        else{
                            q.push_back(D[row][col]);
                            Merge=true;
                        }
                    }
                }
                for(int col=0;col<n;col++)
                {
                    if(col<q.size())
                        D[row][col+1]=q[col];
                    else
                        D[row][col+1]=0;
                }
                // for(int col=0;col<q.size();col++)
                // {
                //     D[row][col]=q[col];
                // }
            }
        }
        // cout<<i<<"번쨰 시도 : 방향 : "<<direction[i]<<'\n';
        // for(int row=1;row<=n;row++)
        // {
        //     for(int col=1;col<=n;col++)
        //     {
        //         cout<<D[row][col]<<" ";
        //     }
        //     cout<<'\n';
        // }
    }
    eval();
}
void whichDirection(){
    if(direction.size()==5)
    {
        excute();
        return ;
    }
    for(int i=1;i<=4;i++)
    {
        direction.push_back(i);
        whichDirection();
        direction.pop_back();
    }
    return ;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++){
            cin>>Origin[i][j];
        }
    }
    whichDirection();
    cout<<ans;
}