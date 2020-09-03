#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int originData[51][51];
int n,m;
int ans=0x3f3f3f3f;
vector<int> seq;
vector <pair<pair<int,int>,int>> oper;
void cal(){
    int d[51][51];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           d[i][j]=originData[i][j]; 
        }
    }
    for(int k=0;k<seq.size();k++){
        int r = oper[seq[k]].first.first;
        int c = oper[seq[k]].first.second;
        int s = oper[seq[k]].second;
        for(int cs = 1;cs<=s;cs++){
            int tmp = d[r-cs][c-cs];
            for(int i=r-cs;i<=r+cs-1;i++){
                d[i][c-cs]=d[i+1][c-cs];
            }
            for(int i=c-cs;i<c+cs;i++){
                d[r+cs][i]=d[r+cs][i+1];
            }
            for(int i=r+cs;i>r-cs;i--){
                d[i][c+cs]=d[i-1][c+cs];
            }
            for(int i=c+cs;i>c-cs;i--){
                d[r-cs][i]=d[r-cs][i-1];
            }
            d[r-cs][c-cs+1]=tmp;
        }
        // cout<<"**************\n";
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         cout<<d[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"**************";
    }
    int minRow=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        int tmp =0;
        for(int j=1;j<=m;j++){
            tmp+=d[i][j];
        }
        minRow=min(minRow,tmp);
    }
    ans=min(ans,minRow);
}
int main(){
    int k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>originData[i][j];
        }
    }
    int x,y,z;

    for(int i=0;i<k;i++){
        cin>>x>>y>>z;
        oper.push_back({{x,y},z});
        seq.push_back(i);
    }

    do{
        cal();
    }while(next_permutation(seq.begin(),seq.end()));
    cout<<ans;
}   