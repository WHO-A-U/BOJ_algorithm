#include <bits/stdc++.h>
using namespace std;
int v[800000][2];
int d[5001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int w,n;
    cin>>w>>n;
    
    for(int i=0;i<n;i++){
        cin>>d[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(d[i]+d[j]<w&&v[d[i]+d[j]][1]==0){
                v[d[i]+d[j]][0]=i;
                v[d[i]+d[j]][1]=j;
            }
        }
    }

    bool flag=false;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int rest = w-(d[i]+d[j]);
            if(d[i]+d[j]<w&&(rest)>=2){
                if(v[rest][1]!=0){
                    if(i!=v[rest][0]&&j!=v[rest][1]&&j!=v[rest][0]&&i!=v[rest][1]){
                        flag=true;
                        break;
                    }
                }
            }
        }
    }
    if(flag){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}