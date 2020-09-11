#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool flag=false;
bool start= false;
int d[11];
int n;
long long expressNum(){
    long long tmp=0;
    for(int i=0;i<11;i++){
        tmp*=10;
        tmp+=d[i];
    }
    return tmp;
}
void go(int digit){

    if(digit>10){
        if(n==0)
            flag=true;
        n--;
        return ;
    }
    if(start){
        for(int i=0;i<10;i++){
            if(d[digit-1]>i){
                d[digit]=i;
                go(digit+1);
                if(flag)return ;
                d[digit]=0;
            }
        }
    }else{
        d[digit]=0;
        go(digit+1);
        if(flag)return ;
        for(int i=1;i<10;i++){
            start=true;
            d[digit]=i;
            go(digit+1);
            if(flag)return ;
            d[digit]=0;
            start=false;
        }

    }
}
int main(){
    cin>>n;
    if(n>1022){
        cout<<"-1";
        return 0;
    }
    go(0);
    cout<<expressNum();
}