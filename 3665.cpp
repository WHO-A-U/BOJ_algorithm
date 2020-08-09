#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
bool v[501][501];
int degree[501];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> d(n+1);
        memset(v,false,sizeof(v));
        memset(degree,0,sizeof(degree));
        for(int i=0;i<n;i++){
            cin>>d[i];
            degree[d[i]]=0;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                v[d[i]][d[j]]=true;
                degree[d[j]]++;
            }
        }
        cin>>m;
        int a,b;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            v[a][b]=!v[a][b];
            v[b][a]=!v[a][b];
            if(v[a][b]){
                degree[a]--;
                degree[b]++;               
            }
            else{
                degree[a]++;
                degree[b]--;
            }
        }
        queue<int> q;
        vector<int>ans;

        for(int i=1;i<=n;i++){
            if(degree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int cur=q.front();
            q.pop();
            degree[cur]--;
            ans.push_back(cur);
            for(int i=1;i<=n;i++){
                if(v[cur][i])
                    degree[i]--;
                if(degree[i]==0)
                    q.push(i);
            }
            
        }
        if(ans.size()==n){
            for(int i=0;i<ans.size();i++)
                cout<<ans[i]<<" ";
            cout<<'\n';
        }
        else{
            cout<<"IMPOSSIBLE\n";
        }
    
    }
}