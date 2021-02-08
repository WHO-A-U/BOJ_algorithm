#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
vector<pair<int,int>> v[5];
vector<pair<int,int>> m;
bool visit[51];
int getMinScore(int idx){
    int curPoint = m[idx].second;
    bool b[51][2];
    memset(b,false,sizeof(b));
    int curIdx = idx+1>=m.size()?0:idx+1;
    while(m[curIdx].second!=curPoint){
        int cp = m[curIdx].second;
        b[cp][0]=!b[cp][0];
        curIdx = (curIdx+1)%m.size();
    }
    curIdx = idx-1<0?m.size()-1:idx-1;
    while(m[curIdx].second!=curPoint){
        int cp = m[curIdx].second;
        b[cp][1]=!b[cp][1];
        curIdx = (curIdx-1)>=0?curIdx-1:m.size()-1;
    }
    int cnt[2]={0,0};
    for(int i=0;i<2;i++){
        for(int j=0;j<51;j++){
            if(b[j][i]){
                cnt[i]++;
            }
        }
    }
    return min(cnt[0],cnt[1]);
}
int main(){
    int n,num1,idx1,num2,idx2,ans1=0,ans2=0;
    cin>>n;
    memset(visit,false,sizeof(visit));
    for(int i=1;i<=n/2;i++){
        cin>>num1>>idx1>>num2>>idx2;
        v[num1].push_back({idx1,i});
        v[num2].push_back({idx2,i});
    }
    for(int i=1;i<=4;i++){
        sort(v[i].begin(),v[i].end());
    }
    for(int i=0;i<v[1].size();i++)m.push_back(v[1][i]);
    for(int i=0;i<v[4].size();i++)m.push_back(v[4][i]);
    for(int i=v[2].size()-1;i>=0;i--)m.push_back(v[2][i]);
    for(int i=v[3].size()-1;i>=0;i--)m.push_back(v[3][i]);
    for(int i=0;i<m.size();i++){
        if(!visit[m[i].second]){
            visit[m[i].second]=true;
            int cur = getMinScore(i);
            ans1+=cur;
            ans2 = max(ans2,cur);
        }
    }
    cout<<ans1/2<<"\n"<<ans2;

}