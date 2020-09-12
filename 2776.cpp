#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
vector<int> A;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x;
    cin>>t;
    while(t--){
        A.clear();
        cin>>n;
        while(n--){
            cin>>x;
            A.push_back(x);
        }
        cin>>n;
        sort(A.begin(),A.end());
        while(n--){
            cin>>x;
            int l=0,r=A.size()-1,mid,ans=-1;
            while(l<=r){
                mid=(l+r)/2;
                if(A[mid]==x){
                    ans=mid;
                    break;
                }
                if(A[mid]>x){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            if(ans==-1){
                cout<<"0\n";
            }else{
                cout<<"1\n";
            }
        }
    }
}