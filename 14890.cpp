#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int d[101][101];
int n,l,ans=0;;
void rowCal(int idx){
    vector<int> v;
    vector<int> BRDG(n,0);
    for(int i=1;i<n;i++){
        if(abs(d[idx][i]-d[idx][i-1])>1)
            return ;
        if(d[idx][i]!=d[idx][i-1])
            v.push_back(d[idx][i]-d[idx][i-1]);
        else
            v.push_back(0);

    }
    for(int i=0;i<v.size();i++){
        if(v[i]==1){
            if(i-l+1<0)
                return ;
            for(int j=i;j>i-l;j--){
                if(BRDG[j]==0)
                    BRDG[j]=1;
                else 
                    return ;
            }
        }
        if(v[i]==-1){
            for(int j=i+1;j<i+l+1;j++)
            {
                if(j>=n||BRDG[j]==1)
                    return ;
                BRDG[j]=1;
            }
        }
    }
    ans++;
    return ;
}
void colCal(int idx){
    vector<int> v;
    vector<int> BRDG(n,0);
    for(int i=1;i<n;i++){
        if(abs(d[i][idx]-d[i-1][idx])>1)
            return ;
        if(d[i][idx]!=d[i-1][idx])
            v.push_back(d[i][idx]-d[i-1][idx]);
        else
            v.push_back(0);

    }
    for(int i=0;i<v.size();i++){
        if(v[i]==1){
            if(i-l+1<0)
                return ;
            for(int j=i;j>i-l;j--){
                if(BRDG[j]==0)
                    BRDG[j]=1;
                else 
                    return ;
            }
        }
        if(v[i]==-1){
            for(int j=i+1;j<i+l+1;j++)
            {
                if(j>=n||BRDG[j]==1)
                    return ;
                BRDG[j]=1;
            }
        }
    }
    ans++;
    return ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>l;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];
        }
    }
    for(int i=0;i<n;i++){
        rowCal(i);
        colCal(i);
    }    
    cout<<ans;
}