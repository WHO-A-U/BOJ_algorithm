#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> var;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,x;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>x;
        var.push_back(x);
    }
    sort(var.begin(),var.end());
    cin>>M;
    for(int i=0;i<M;i++)
    {
        cin>>x;
        int low=0,high=var.size()-1; //not real value only index
        while(1){
            if(low>high){
                cout<<0<<'\n';
                break;
            }
            int mid=(low+high)/2;
            if(var[mid]==x){
                cout<<1<<'\n';
                break;
            }
            if(var[mid]>x){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    }
}