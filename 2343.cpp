#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> record;
int n,m,x;
bool isPossible(long long  maxBlueSize){
    long long bluecnt=1;
    long long tmp=0;
    for(int i=0;i<n;i++){
        if(record[i]>maxBlueSize)
            return false;
        if(tmp+record[i]>maxBlueSize){
            bluecnt++;
            tmp=record[i];
        }else{
            tmp+=record[i];
        }
    }
    return bluecnt<=m;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        record.push_back(x);
    }
    long long l=1,r=1000000000,mid;
    while(l<r){
        mid=(r+l)/2;
        if(isPossible(mid)){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<r;
}