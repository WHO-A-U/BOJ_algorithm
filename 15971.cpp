#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define INF 0x3f3f3f3f
using namespace std;
vector<pair<int,int>> edge[100001];
vector<int> st;
vector<int> dist;
bool visit[100001];
int n, r1,r2;
int calMin(vector<int> &ans){
    int sum=0;
    int maxVal=0;
    for(int i=0;i<ans.size();i++){
        sum+=ans[i];
        maxVal=max(maxVal,ans[i]);
    }
    return sum-maxVal;
}
int main(){
    // cout<<INF<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>r1>>r2;
    int x,y,z;
    for(int i=0;i<n-1;i++){
        cin>>x>>y>>z;
        edge[x].push_back({y,z});
        edge[y].push_back({x,z});
    }

    int sum=0;
    visit[r1]=true;
    if(r1==r2){
        cout<<0;
        return 0;
    }
    st.push_back(r1);
    int cur;
    int minVal=INF;
    bool flag=false;
    pair<int,int> p;
    while(st.size()!=0){
        // cout<<"!";
        cur=st.back();      
        // cout<<cur<<" : ";
        // for(int i=0;i<dist.size();i++){
        //     cout<<dist[i]<<" ";
        // }
        // cout<<"\n";
        flag=false;
        for(int i=0;i<edge[cur].size();i++){
            p = edge[cur][i];
            if(!visit[p.first]){
                visit[p.first]=true;
                flag=true;
                st.push_back(p.first);
                dist.push_back(p.second);
                if(p.first==r2){
                    minVal=min(minVal,calMin(dist));
                }
                break;
            }
        }
        if(!flag){
            st.pop_back();
            dist.pop_back();
        }
    }
    cout<<minVal;
}