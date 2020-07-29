#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int d[1001][1001];
vector<pair<int,int>> v[19];
int ans=0;
int n,m;
void cal(int r,int c){
   for(int i=0;i<19;i++){
    int cr = r;
    int cc = c;
    int tmp=d[cr][cc];
    for(int j=0;j<v[i].size();j++){
        cr+=v[i][j].first;
        cc+=v[i][j].second;
        if(cr<0||cr>=n||cc<0||cc>=m){
            tmp=0;
            break;
        }
        tmp+=d[cr][cc];
    }
    ans=max(ans,tmp);
   }
}
void init(){
    v[0].push_back({1,0});
    v[0].push_back({1,0});
    v[0].push_back({1,0});

    v[1].push_back({0,1});
    v[1].push_back({0,1});
    v[1].push_back({0,1});
    
    v[2].push_back({1,0});
    v[2].push_back({0,1});
    v[2].push_back({-1,0});
    
    v[3].push_back({1,0});
    v[3].push_back({1,0});
    v[3].push_back({0,1});
    
    v[4].push_back({0,1});
    v[4].push_back({0,1}); //     a
    v[4].push_back({-1,0});// a a a
    
    v[5].push_back({0,1});//a a
    v[5].push_back({1,0});//  a
    v[5].push_back({1,0});//  a
    
    v[6].push_back({1,0});// a a a 
    v[6].push_back({-1,1});//a
    v[6].push_back({0,1});
    
    v[7].push_back({1,0});
    v[7].push_back({0,1});
    v[7].push_back({1,0});
    
    v[8].push_back({0,1});
    v[8].push_back({-1,0});
    v[8].push_back({0,1});
    
    v[9].push_back({1,0});
    v[9].push_back({0,1});
    v[9].push_back({0,-2});
    
    v[10].push_back({1,0});
    v[10].push_back({1,0});
    v[10].push_back({-1,1});
    
    v[11].push_back({0,1});
    v[11].push_back({0,1});
    v[11].push_back({1,-1});

    v[12].push_back({1,0});
    v[12].push_back({1,0});
    v[12].push_back({-1,-1});

    v[13].push_back({1,0});
    v[13].push_back({0,-1});
    v[13].push_back({1,0});

    v[14].push_back({0,1});
    v[14].push_back({1,0});
    v[14].push_back({0,1});


    //a
    //a a a
    v[15].push_back({1,0});
    v[15].push_back({0,1});
    v[15].push_back({0,1});


    // a
    // a
    //aa
    v[16].push_back({1,0});
    v[16].push_back({1,0});
    v[16].push_back({0,-1});

    //a a a
    //    a
    v[17].push_back({0,1});
    v[17].push_back({0,1});
    v[17].push_back({1,0});

    //a a
    //a
    //a
    v[18].push_back({0,1});
    v[18].push_back({1,-1});
    v[18].push_back({1,0});
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>d[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cal(i,j);
        }
    }
    cout<<ans;
}