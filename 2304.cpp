#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int d[1001][3];
int main(){
    int answer=0;
    memset(d,0,sizeof(d));
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        d[a][0]=b;
    }
    int maxVal=0;
    for(int i=0;i<1001;i++){
        if(d[i][0]>maxVal)maxVal=d[i][0];
        d[i][1]=maxVal;
    }
    maxVal=0;
    for(int i=1000;i>=0;i--){
        if(d[i][0]>maxVal)maxVal=d[i][0];
        d[i][2]=maxVal;
    }
    for(int i=0;i<1001;i++)answer+=min(d[i][1],d[i][2]);
    cout<<answer;
    return 0;
}