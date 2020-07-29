#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
vector<int> v[501];
int d[501],n,x;
int time[501];
int go(int num){
    if(d[num]!=-1)
        return d[num];
    int mintime=0;
    for(int i=0;i<v[num].size();i++){
        mintime = max( mintime , go(v[num][i]) );
    }
    return d[num]=mintime+time[num];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(d,-1,sizeof(d));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>time[i];
        while(1){
            cin>>x;
            if(x==-1)
                break;
            v[i].push_back(x);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<go(i)<<'\n';
    }
}
