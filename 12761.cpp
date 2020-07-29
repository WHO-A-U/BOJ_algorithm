#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int diff[6]={1,-1,0};
int main()
{
    int a,b,n,m;
    cin>>a>>b>>n>>m;
    diff[2]=a;
    diff[3]=-a;
    diff[4]=b;
    diff[5]=-b;
    vector<int> v;
    v.assign(100001,987654321);
    queue<int> q;
    q.push(n);
    v[n]=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int k=0;k<6;k++)
        {
            int next=cur+diff[k];
            if(next>=0&&next<=100000&&v[next]>v[cur]+1)
            {
                
                q.push(next);
                v[next]=v[cur]+1;
            }
            if(next==m)
            {
                cout<<v[next];
                return 0;
            }
        }
        for(int i=1;i<=2;i++)
        {
            int next=cur*diff[2*i];
            if(next>=0&&next<=100000&&v[next]>v[cur]+1)
            {
                q.push(next);
                v[next]=v[cur]+1;
            }
            if(next==m)
            {
                cout<<v[next];
                return 0;
            }
        }
    }
    cout<<v[m]<<endl;
    return 0;
}