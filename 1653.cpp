#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> num;
vector<long long> ans;
int n,x,k;
int d[10];
int w[10]={-5,-4,-3,-2,-1,1,2,3,4,5};
long long balanceNum(){
    long long tmp=0;
    for(int i=0;i<10;i++){
        tmp*=10;
        if(d[i]!=0)
            tmp+=d[i];
    }
    return tmp;
}
void go(int stage,int sum){
    if(stage==n){
        if(sum==0){
            // cout<<'\n';
            // for(int i=0;i<10;i++){
            //     cout<<d[i]<<" ";
            // }
            // cout<<'\n';
            ans.push_back(balanceNum());
        }
        return ;
    }
    for(int i=0;i<10;i++){
        if(d[i]!=0){
            continue;
        }
        else{
            d[i]=num[stage];
            go(stage+1,sum+(d[i]*w[i]));
            d[i]=0;
        }
    }
    go(stage+1,sum);
    return ;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        num.push_back(x);
    }
    cin>>k;
    go(0,0);
    sort(ans.begin(),ans.end());
    // cout<<"\n\n\n";
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" \n";
    // }
    if(k>ans.size()){
        cout<<ans[ans.size()-1];
    }
    else{
        cout<<ans[k];
    }

}