#include<iostream>
using namespace std;
int main(){
    int d[4];
    cin>>d[1]>>d[2]>>d[3];
    double b =(double)(d[1]-d[2]+d[3])/2;
    double a = (double)d[1]-b;
    double c = (double)d[2]-a;
    if(a>0&&b>0&&c>0){
        cout<<"1\n";
        printf("%1.1f %1.1f %1.1f\n",a,b,c);
    }else{
        cout<<"-1";
    }

}