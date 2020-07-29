#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
vector<int> d[4];
map<int,int> A;
map<int,int> B;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long ans=0;
    cin>>n;
    for(int i=0;i<4;i++)
        d[i].assign(n,0);
    for(int i=1;i<=n;i++){
        for(int j=0;j<4;j++){
            cin>>d[j][i];
        }
    }
    for(int i=0;i<d[0].size();i++){
        for(int j=0;j<d[1].size();j++){
            if(A.find(d[0][i]+d[1][j])==A.end())
                A[d[0][i]+d[1][j]]=1;
            else
                A[d[0][i]+d[1][j]]++;
        }
    }
    for(int i=0;i<d[2].size();i++){
        for(int j=0;j<d[3].size();j++){
            if(B.find(d[2][i]+d[3][j])==B.end())
                B[d[2][i]+d[3][j]]=1;
            else
                B[d[2][i]+d[3][j]]++;
        }
    }
    for(auto it=A.begin();it!=A.end();it++){
        if(B.find(-(it->first))!=B.end()){
            ans+=(it->second)*B[-(it->first)];
        }
    }
    cout<<ans;

}