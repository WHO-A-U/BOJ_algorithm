#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
vector<int> middle;
int func(int start,int end,int len){
    if(end-start<=len)
        return 0;
    int x=(end-start)/len;
    if((end-start)%len==0)x--;
    return x;
}
int isPossible(int now){
    int cnt=0;
    for(int i=1;i<middle.size();i++){
        cnt+=func(middle[i-1],middle[i],now);
    }
    return cnt;
}
int main(){
    int n,m,len,x;
    cin>>n>>m>>len;
    middle.push_back(0);
    for(int i=0;i<n;i++){
        cin>>x;
        middle.push_back(x);
    }
    middle.push_back(len);
    int l=0,r=l-1,mid,ans;
    while(l<=r){
        mid=(l+r)/2;
        int cur = isPossible(mid);
        if(cur==m){
            ans=cur;
            r=mid-1;
        }else if(cur<m){
            r=mid-1;
        }else if(cur>m){
            l=mid+1;
        }
    }
    cout<<ans;
}