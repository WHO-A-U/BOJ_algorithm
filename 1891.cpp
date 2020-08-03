#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int d;
    long long x,y;
    string str;
    cin>>d>>str>>x>>y;
    int len=str.length();
    const long long tl=((1LL)<<len);
    long long xlow=0,xhigh=tl;
    long long ylow=0,yhigh=tl;
    long long dx,dy;
    for(int i=0;i<len;i++){
        dx=xhigh-xlow;
        dy=yhigh-ylow;
        if(str[i]=='1'){
            xlow=dx/2+xlow;
            ylow=dy/2+ylow;
        }
        if(str[i]=='2'){
            xhigh=dx/2+xlow;
            ylow=dy/2+ylow;
        }
        if(str[i]=='3'){
            xhigh=dx/2+xlow;
            yhigh=dy/2+ylow;
        }
        if(str[i]=='4'){
            xlow=dx/2+xlow;
            yhigh=dy/2+ylow;
        }
    }
    xlow+=x;
    ylow+=y;
    if(xlow<0||xlow>=tl||ylow<0||ylow>=tl){
        cout<<-1;
        return 0;
    }
    string ans="";
       for(int i=0;i<len;i++){
        long long n=((1LL)<<(len-i-1));
        int dx=xlow/n;
        int dy=ylow/n;
        xlow%=n;
        ylow%=n;
        if(dx==1&&dy==1)ans+="1";
        if(dx==0&&dy==1)ans+="2";
        if(dx==0&&dy==0)ans+="3";
        if(dx==1&&dy==0)ans+="4";
    }
    cout<<ans;
    
}