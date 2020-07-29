#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
#include<queue>
using namespace std;
int d['Z'-'A'+1];
int main()
{
    int n;
    cin>>n;
    string str;
    for(int i=0;i<n;i++)
    {
         cin>>str;
         for(int i=0;i<str.size();i++)
         {
             d[str[str.size()-1-i]-'A']+=pow(10,i);
         }
    }
    priority_queue<int> q;
    for(int i=0;i<'Z'-'A'+1;i++)
    {
        if(d[i]!=0)
            q.push(d[i]);
    }
    int tmp=9;
    long long ans=0;
    while(!q.empty())
    {
        ans+=(q.top()*tmp);
        q.pop();
        tmp--;
    }
    cout<<ans;
}