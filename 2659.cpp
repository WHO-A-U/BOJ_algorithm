#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int ans,clockNum;
vector<int> tmp;
bool v[10000];
int getCrossNum(vector<int> d){
    int ret = 0x3f3f3f3f;
    for(int i=0;i<4;i++){
        int val=0;
        for(int j=0;j<4;j++){
            val*=10;
            val+=d[(i+j)%4];
        }
        ret = min(ret,val);
    }
    return ret;
}
void go(int stage){
    if(stage==4){
        int crossNum = getCrossNum(tmp);
        if(crossNum<clockNum&&!v[crossNum]){
            v[crossNum]=true;
            ans++;
        }
        return ;
    }
    for(int i=1;i<=9;i++){
        tmp.push_back(i);
        go(stage+1);
        tmp.pop_back();
    }
    return ;
}
int main(){
    vector<int> d;
    int x,val=0;;
    ans=0;
    for(int i=0;i<4;i++){
        cin>>x;
        d.push_back(x);
    }
    clockNum=getCrossNum(d);
    go(0);
    cout<<ans+1;
}