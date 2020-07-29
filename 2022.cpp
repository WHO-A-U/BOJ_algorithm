#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
    double x,y,c;
    cin>>x>>y>>c;
    double d=min(x,y);
    double first=0.0;
    double mid=(first+d)/2;
    double x2=x*x;
    double y2=y*y;
    double ans;
    while(1){
        double mid2=mid*mid;
        double a=sqrt(x2-mid2);
        double b=sqrt(y2-mid2);
        ans=(a*b)/(a+b);
        
        if(abs(d-first)<1e-6){
            break;
        }
        if(ans<c){
            d=mid;
            mid=(d+first)/2.0;
        }
        else{
            first=mid;
            mid=(first+d)/2.0;
        }
    }
    cout<<printf("%.4f",mid);
}