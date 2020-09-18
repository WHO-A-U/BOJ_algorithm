#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> A;
vector<int> B;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        A.clear();
        B.clear();
        int a,b,x;
        cin>>a>>b;
        for(int i=0;i<a;i++){
            cin>>x;
            A.push_back(x);
        }
        for(int i=0;i<b;i++){
            cin>>x;
            B.push_back(x);
        }
        sort(B.begin(),B.end());
        int cnt=0;
        for(int i=0;i<a;i++){
            int l=0,r=b-1,mid,ans=-1;
            while(l<=r){
                mid=(l+r)/2;
                if(B[mid]<A[i]){
                    l=mid+1;
                    ans=mid;
                }
                else{
                    r=mid-1;
                }
            }
            cnt+=ans+1;
        }
        cout<<cnt<<"\n";
    }
}