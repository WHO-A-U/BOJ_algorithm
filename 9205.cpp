#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
vector<pair<int,int>> v;
vector<int> Edge[102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,x,y,sx,sy,dx,dy;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>sx>>sy;
        v.clear();
        for(int i=0;i<101;i++)
            Edge[i].clear();
        v.push_back({sx,sy});
        for(int i=1;i<=n+1;i++)
        {
            cin>>x>>y;
            v.push_back({x,y});
            for(int j=0;j<i;j++)
            {
                int dist=abs(v[i].first-v[j].first)+abs(v[i].second-v[j].second);
                if(dist<=1000)
                {
                    Edge[i].push_back(j);
                    Edge[j].push_back(i);
                }
            }
        }
        queue<int> q;
        bool visit[102];
        memset(visit,false,sizeof(visit));
        visit[0]=true;
        q.push(0);
        while(!q.empty())
        {
            int cNode=q.front();
            q.pop();
            for(int i=0;i<Edge[cNode].size();i++)
            {
                if(visit[Edge[cNode][i]]==false){
                    visit[Edge[cNode][i]]=true;
                    q.push(Edge[cNode][i]);
                }
            }
        }
        if(visit[n+1])
            cout<<"happy\n";
        else
            cout<<"sad\n";
        
    }
}