#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
int d[101][101];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int r,c,dir,g;
        cin>>c>>r>>dir>>g;
        vector<int> tmp;
        tmp.push_back(dir);
        for(int j=0;j<g;j++){
            auto tmp2=tmp;
            for(int k=tmp2.size()-1;k>=0;k--){
                tmp.push_back((tmp2[k]+1)%4);
            }
        }
        d[r][c]=1;
        for(int j=0;j<tmp.size();j++){
            r+=dx[tmp[j]];
            c+=dy[tmp[j]];
            d[r][c]=1;
        }
    }
    int ans=0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(d[i][j]&&d[i+1][j]&&d[i][j+1]&&d[i+1][j+1])
                ans++;
        }
    }
    cout<<ans;
}