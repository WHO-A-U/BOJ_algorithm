#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
char v[56];
vector<int> ans;
int n;
bool isRight(int from,int to,char op){
    int sum=0;
    for(int i=from-1;i<to;i++)
        sum+=ans[i];
    if((sum>0&&op=='+')||(sum==0&&op=='0')||(sum<0&&op=='-'))
        return true;
    return false;
}
void go(int num){
    if(num>n)
    {
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
        exit(0);
    }
    for(int i=-10;i<=10;i++)
    {
        int s=n-1;
        int k=num;
        bool flag=true;
        ans.push_back(i);
        for(int j=1;j<=num;j++)
        {
            if(isRight(j,num,v[k-1])){
                k=k+s;
                s--;
            }
            else{
                ans.pop_back();
                flag=false;
                break;
            }
        }
        if(flag)
        {
            go(num+1);
            ans.pop_back();
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<(n*(n+1))/2;i++)
    {
        cin>>v[i];
    }
    go(1);
   
}