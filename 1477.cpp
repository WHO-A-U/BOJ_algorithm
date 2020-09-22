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
int isPossible(int now){ //함수 수정 최의 인터벌으 넣었을때 그렇게 해서 가능한 휴게소의 개수를 출력해야함
    int cnt=0;
    for(int i=1;i<middle.size();i++){
        int t=func(middle[i-1],middle[i],now);
        cnt+=t;
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,len,x;
    cin>>n>>m>>len;
    middle.push_back(0);
    for(int i=0;i<n;i++){
        cin>>x;
        middle.push_back(x);
    }
    middle.push_back(len);
    sort(middle.begin(),middle.end());
    int l=1,r=len,mid,ans;
    while(l<=r){
        mid=(l+r)/2;
        int cur = isPossible(mid);
        if(cur==m){
            ans=mid;
            r=mid-1;
        }else if(cur<m){
            ans=mid;
            r=mid-1;
        }else if(cur>m){
            l=mid+1;
        }
    }
    cout<<ans;
}