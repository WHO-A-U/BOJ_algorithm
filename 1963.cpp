#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
vector<int> prime;
bool isP[10000];
vector<int> node[10000];
int ds[]={1,10,100,1000,10000};
int go(int from , int to){
    if(from == to)
        return 0;
    queue<pair<int,int>> q; //  num , cost
    bool visit[10000];
    memset(visit,false,sizeof(visit));
    q.push({from,0});
    visit[from]=true;
    while(!q.empty()){
        int cur=q.front().first;
        int cost = q.front().second;
        q.pop();
        for(int i=0;i<node[cur].size();i++){
            if(!visit[node[cur][i]]){
                if(node[cur][i]==to)
                    return cost+1;
                else{
                    visit[node[cur][i]]=true;
                    q.push({node[cur][i],cost+1});
                }
            }
        }
    }
    return -1;
}
int main(){
    memset(isP,true,sizeof(isP));
    for(int i=4;i<10000;i+=2){
        isP[i]=false;
    }
    for(int i=3;i<10000;i++){
        if(!isP[i])
            continue;
        bool flag=true;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0){
                flag=false;
                break;
            }
        }
        if(flag==false){
            for(int j=i;j<10000;j+=i){
                isP[j]=false;
            }
        }
    }
    for(int i=1000;i<10000;i++){
        if(isP[i]){
            prime.push_back(i);
        }
    }
    for(int i=0;i<prime.size();i++){
        int digit[4];
        for(int j=0;j<4;j++)
            digit[j]=((prime[i])%ds[j+1])/ds[j]; 
        for(int j=0;j<4;j++){
            int tmp=0;
            for(int k=0;k<4;k++){
                if(k!=j){
                    tmp+=digit[k]*ds[k];
                }
            }
            for(int k=0;k<10;k++){
                int nextP=tmp+k*ds[j];
                if(nextP==prime[i]||isP[nextP]==false||nextP<1000)
                    continue;
                node[prime[i]].push_back(nextP);
                node[nextP].push_back(prime[i]);
            }
        }

    }
    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        int ans=go(a,b);
        if(ans==-1)
            cout<<"Impossible\n";
        else
            cout<<ans<<'\n';
    }

}