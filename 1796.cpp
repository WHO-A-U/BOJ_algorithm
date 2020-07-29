#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
#define INF 987654321;
vector<int> v;
int d['z'-'a'+1][2]; //first  last
int go(int cur,int alpha,int ans){
    int first=d[alpha][0];
    int last=d[alpha][1];
    if(alpha>'z'-'a'){
        return ans;
    }
    if(first>last){
        //해당 알파벳이 없는 경우
        return go(cur,alpha+1,ans);
    }
    else if(first==last){
        return go(first,alpha+1,ans+abs(cur-first));
    } else if(last<cur){
        return go(first,alpha+1,ans+(cur-first));
    } else if(first>cur){
        return go(last,alpha+1,ans+(last-cur));
    }
    else {
        int goright=go(first,alpha+1,ans+(last-cur)+(last-first));
        int goleft=go(last,alpha+1,ans+(cur-first)+(last-first));
        return min(goright,goleft);
    }
}
int main()
{
    for(int i=0;i<='z'-'a';i++)
    {
        d[i][0]=INF;
        d[i][1]=-1;
    }
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        d[s[i]-'a'][0]=min(d[s[i]-'a'][0],i); //find alphabet's first index
        d[s[i]-'a'][1]=max(d[s[i]-'a'][1],i); //      ```       second ```
    }
    int ans=0;
    ans=go(0,0,0);
    ans+=s.size();
    cout<<ans;
}