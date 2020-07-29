#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int M=987654321;
vector<int> v;

int go(int x){
    if (x==n)
    {
        for(int i=0;i<v.size();i++)
            cout<<v[i];
    }
    for(int i=1;i<=3;i++)
    {
        if(v.size()==0){
            v.push_back(i);
            go(x+1);
            v.pop_back();
        }
        else{
            if(v[x-1]!=i){
                v.push_back(i);
                go(x+1);
            }
        }
    }
}
int main()
{
    cin>>n;
    go(0);
}