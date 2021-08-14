#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define INF 0x3f3f3f3f
using namespace std;
int d[1111][2];
int n,t;
int isPossible(int s){
    int minSum=0,restSum=0;

    for(int i=0;i<n;i++){
        if( s < d[i][0])
            return 1; //  s를 올려야함
        
        minSum+=d[i][0];
        restSum += min(s,d[i][1]);
    }
    if(minSum <= t && t <=restSum){
        return 0; //s 를 내려봐도됨 일단 정답
    }else if(restSum < t){
        // s 를 올려야함
        return 1;
    }else{ // minSum > t
        return -1;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>t;
    
    int l=0,r=0,mid;

    for(int i=0;i<n;i++){
        cin>>d[i][0]>>d[i][1];
        l = max(l,d[i][0]);
        r = max(r,d[i][1]);
    }

    int ans = INF;

    while(l<=r){
        mid = (l+r)/2;
        
        int flag = isPossible(mid);
        // printf("l : %d r : %d mid : %d flag = %d\n",l,r,mid,flag);
        if( flag == 0 ){
            ans = min(ans , mid);
            r = mid - 1;

        }else{
            l = mid + 1;
        }
    }
    if(ans == INF){
        cout<<-1;
    }else{
        cout<<ans;
    }
    
}