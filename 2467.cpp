#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<long long > pos,neg;
bool zero=false;
long long ans=0x3f3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x==0)
            zero=true;
        if(x>0)
            pos.push_back(x);
        if(x<0)
            neg.push_back(x);
    }
    sort(neg.begin(),neg.end(),greater<long long>());
    int i=0,j=0;
    if(pos.size()==0||neg.size()==0){
        if(zero){
            if(pos.size()==0)
                cout<<neg[0]<<" 0";
            else
                cout<<"0 "<<pos[0];
        }
        else{
            if(pos.size()==0)
                cout<<neg[1]<<" "<<neg[0];
            else
                cout<<pos[0]<<" "<<pos[1];
        }
    }
    else{
        pos.push_back(1000000000);
        neg.push_back(1000000000);
        long long a,b;
        while(i!=pos.size()-1&&j!=neg.size()-1){
            if(abs(pos[i]+neg[j])<ans){
                b=pos[i];
                a=neg[j];
                ans=abs(pos[i]+neg[j]);
            }
                if(abs(pos[i+1]+neg[j])<abs(pos[i]+neg[j+1])){
                    i++;
                }
                else{
                    j++;
                }
            }
        cout<<a<<" "<<b;
    }
    
}