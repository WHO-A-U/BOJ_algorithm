#include<iostream>
#include <iomanip>
#include<cmath>
using namespace std;
double cal(double x1,double y1,double z1,double x2,double y2, double z2){
    return (sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1)  ));
}
int main()
{
    double x1,x2,x3,y1,y2,y3,z1,z2,z3;
    cin>>x1>>y1>>z1>>x2>>y2>>z2>>x3>>y3>>z3;
    double dx=x2-x1,dy=y2-y1,dz=z2-z1;
    double left=0.0,right=1.0;
    double m=0;
    while(1){
        if(abs(left-right)<1e-9){
            m=(left+right)/2;
            break;
        }
        double m1=left+(right-left)/3;
        double m2=right-(right-left)/3;
        double m1x = x1 + m1*dx; //
        double m1y = y1 + m1*dy;
        double m1z = z1 + m1*dz;
        double m2x = x1 + m2*dx;
        double m2y = y1 + m2*dy;
        double m2z = z1 + m2*dz;
        double d1=cal(x3,y3,z3,m1x,m1y,m1z);//뒤
        double d2=cal(x3,y3,z3,m2x,m2y,m2z);//앞
        if(d1>d2)
        {
            left=m1;
        }
        else{
            right=m2;
        }
    }
    double xa=x1+m*dx, ya=y1+m*dy,za=z1+m*dz;
    double ans=cal(xa,ya,za,x3,y3,z3);
    cout << fixed << setprecision(10) << ans << '\n';
}