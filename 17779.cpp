#include<iostream>
#include<algorithm>
using namespace std;
int m[22][22];
int main(){
    int n;
    cin>>n;
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            cin>>m[x][y];
            m[x][y]+=m[x][y-1];
        }
    }
    int ans=0x3f3f3f3f;
    for(int x=1;x<=n-2;x++){
        for(int y=2;y<=n-1;y++){
            for(int k=2;k<=n-x;k++){
                for(int d=1;d<k;d++){
                    int d1 = d;
                    int d2 = k-d;
                    if(y-d1<1||y+d2>n)
                        continue;
                    int lp=y,rp=y;
                    int left=false,right=false;
                    int a[6]={0,0,0,0,0,0};
                    for(int i=1;i<=n;i++){
                        if(i<x){
                            a[1]+=(m[i][y]-m[i][0]);
                            a[2]+=(m[i][n]-m[i][y]);
                        }
                        else if(x<=i&&i<=x+k){
                            a[5]+=m[i][rp]-m[i][lp-1];
                            if(!left){
                                a[1]+=(m[i][lp-1]-m[i][0]);
                                lp--;
                                if(y-lp==d1)
                                    left=true;
                            }
                            else{
                                a[3]+=(m[i][lp-1]-m[i][0]);
                                lp++;
                            }
                            if(!right){
                                a[2]+=(m[i][n]-m[i][rp]);
                                if(rp-y==d2){
                                    right=true;
                                    rp--;
                                }
                                else 
                                    rp++;
                            }
                            else{
                                a[4]+=(m[i][n]-m[i][rp]);
                                rp--;
                            }
                            if(i==x+k){
                                lp--;
                                rp++;
                            }
                        }else{
                            a[3]+=(m[i][lp-1]-m[i][0]);
                            a[4]+=(m[i][n]-m[i][lp-1]);
                        }
                    }
                    int minval = min({a[1],a[2],a[3],a[4],a[5]});
                    int maxval = max({a[1],a[2],a[3],a[4],a[5]});
                    ans= min(ans,maxval-minval);
                }
            }
        }
    }
    cout<<ans;
}