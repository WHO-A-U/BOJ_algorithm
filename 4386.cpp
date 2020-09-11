#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
vector<pair<double,double>> v;
double dist[101][101];
int main(){
    
    int n;
    double x,y;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        v.push_back({x,y});
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double x1=v[i].first;
            double y1=v[i].second;
            double x2=v[j].first;
            double y2=v[j].second;
            dist[i][j]=dist[j][i]=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        }
    }
    bool visit[101];
    memset(visit,false,sizeof(visit));
    visit[0]=true;
    int s=0;
    double MST[101];
    double ans=0;
    for(int i=0;i<n;i++)MST[i]=1e+9;
    for(int i=0;i<n-1;i++){
        int idx=-1;
        double mindist=1e+9;
        for(int j=0;j<n;j++){
            if(s!=j){
                MST[j]=min(MST[j],dist[s][j]);
                if(MST[j]<mindist&&!visit[j]){
                    mindist=MST[j];
                    idx=j;
                }
            }
        }
        visit[idx]=true;
        ans+=MST[idx];
        s=idx;
    }
    cout<<ans;
    

}