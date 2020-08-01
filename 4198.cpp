#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> d(n);
    vector<int> len(4004);
    for(int i=0;i<n;i++)
        cin>>d[i];
    if(n==0||n==1){
        cout<<n;
        return 0;
    }
    int ans=0;
    for(int j=0;j<n;j++){
        int low=2001,high=2002;
        len[low]=d[j];
        for(int i=j+1;i<n;i++){
            auto p = lower_bound(&len[low],&len[low]+(high-low),d[i]);
            if(p== &len[high]){
                len[high++]=d[i];
            }
            else if(p== &len[low]){
                len[--low]=d[i];
            }
            else{
                if(d[i]<d[j]){
                    *(p-1)=d[i];
                }
                else{
                    *p = d[i];
                }
            }
        }
        ans=max(ans,high-low);
    }
    cout<<ans;

}