#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int D[1003][201][12];
vector<int> Day;
int n,m,x;
int penalty(int a,int b){
    return a>b?(a-b)*(a-b):0;
}
int go(int day,int rest,int diff){
    if(day==n-1)
        return 0;
    if(D[day][rest][diff]!=-1) return D[day][rest][diff];
    int minval=0x3f3f3f;
    for(int i=0;i<=min(10,rest);i++)
    {
        minval=min(minval,go(day+1,rest-i,i)+penalty(Day[day]+diff,Day[day+1]+i));
    }
    return D[day][rest][diff]=minval;
}
int main(){
    memset(D,-1,sizeof(D));
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        Day.push_back(x);
    }
    cout<<go(0,m,0);
}