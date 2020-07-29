#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
vector<pair<int,pair<int,int>>>v[11];
long long d[11][2];//[i][0]//분자 [i][1] 분모
bool visit[11];
long long gcd(long long a,long long b){
    if(a<b)
    {
        long long tmp=a;
        a=b;
        b=tmp;
    }
    long long r;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main(){
    int n,a,b,p,q;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b>>p>>q;
        v[a].push_back({b,{p,q}});
        v[b].push_back({a,{q,p}});
    }
    for(int i=0;i<n;i++)
        d[i][1]=d[i][0]=1;
    queue<int> que;
    que.push(0);
    visit[0]=true;
    while(!que.empty()){
        int cur = que.front();
        // cout<<cur<<" ";
        que.pop();
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i].first;
            int up=v[cur][i].second.first;
            int down=v[cur][i].second.second;
            if(visit[next]==true){
                continue;
            }
            else{
                visit[next]=true;
                que.push(next);
                d[next][0]=d[cur][0]*down;
                d[next][1]=d[cur][1]*up;
            }
        }
    }
    for(int i=0;i<n;i++){
        long long tmp =gcd(d[i][1],d[i][0]);
        d[i][0]/=tmp;
        d[i][1]/=tmp;
    }
    // cout<<endl;   
    // for(int i=0;i<n;i++)
    //     cout<<d[i][0]<<" ";
    // cout<<endl;   
    // for(int i=0;i<n;i++)
    //     cout<<d[i][1]<<" ";
    // cout<<endl;
    long long G=d[0][1];
    for(int i=0;i<n;i++){
        G=gcd(d[i][1],G);
    }
    // cout<<"1 !"<<G<<"!!\n";
    long long L=1;
    for(int i=0;i<n;i++){
        L*=(d[i][1]/G);
    }
    // cout<<"L !"<<L<<"!!\n";
    for(int i=0;i<n;i++){
        d[i][0]=d[i][0]*(L/d[i][1]);
    }
    // cout<<endl;   
    // for(int i=0;i<n;i++)
    //     cout<<d[i][0]<<" ";
    // cout<<endl;   
    // for(int i=0;i<n;i++)
    //     cout<<d[i][1]<<" ";
    // cout<<endl;
    G=d[0][0];
    for(int i=0;i<n;i++){
        
        G=gcd(d[i][0],G);
        // cout<<i<<"!for!"<<G<<"!!\n";
    }
    
    // cout<<"3 !"<<G<<"!!\n";
    for(int i=0;i<n;i++){
        d[i][0]=d[i][0]/G;
    }
    // cout<<"d[i][0]\n";
    // for(int i=0;i<n;i++){
    //     cout<<d[i][0]<<" ";
    // }
    // cout<<endl;
    for(int i=0;i<n;i++){
        cout<<d[i][0]<<" ";
    }
}

