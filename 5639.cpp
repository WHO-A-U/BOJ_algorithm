#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1000000
using namespace std;
int d[MAX][2];
vector<int> v;
int go(int l ,int r){
    if(l>r){
        return -1;
    }
    int cur = v[l];
    int leftStart=MAX,leftEnd=-1,rightStart=MAX,rightEnd=-1;
    for(int i=l+1;i<=r;i++){
        if(v[i]>cur){
            rightStart = min(rightStart,i);
            rightEnd=i;
        }else{
            leftStart = min(leftStart,i);
            leftEnd=i;
        }
    }
    d[cur][0]=go(leftStart,leftEnd);
    d[cur][1]=go(rightStart,rightEnd);
    return cur;
}
void postOrder(int cur){
    if(cur==-1){
        return ;
    }
    postOrder(d[cur][0]);
    postOrder(d[cur][1]);
    cout<<cur<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    while(cin>>x){
        v.push_back(x);
    }
    for(int i=0;i<MAX;i++){
        d[i][0]=d[i][1]=-1;
    }
    int n = v.size();
    int root = go(0,n-1);
    postOrder(root);
}