#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
vector<ll> pos,neg;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ll x;
    cin>>n;
    bool zero=false;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x==0)zero=true;
        if(x>0)pos.push_back(x);
        if(x<0)neg.push_back(x);
    }
    sort(pos.begin(),pos.end());
    sort(neg.rbegin(),neg.rend());
 
   
    if(pos.size()==0){
        if(zero){
            cout<<neg[0]<<" 0";
        }
        else{
            cout<<neg[1]<<" "<<neg[0];
        }
        return 0;
    }
    if(neg.size()==0){
        if(zero){
            cout<<"0 "<<pos[0];
        }else{
            cout<<pos[0]<<" "<<pos[1];
        }
        return 0;
    } 
    int i=0,j=0;
    ll minval = 0x7f7f7f7f;
    pair<ll,ll> coord={-1,-1};

    while(i<=pos.size()-1||j<=neg.size()-1){
        ll cur = pos[i]+neg[j];
        // cout<<i<<" : "<<j<<"\n";
        if(abs(cur)<minval){
            minval=abs(cur);
            coord = {pos[i],neg[j]};
        }
        if(i==pos.size()-1&&j==neg.size()-1)
            break;
        if(i==pos.size()-1){
            j++;
            continue;
        }
        if(j==neg.size()-1){
            i++;
            continue;
        }
        if(cur==0){
            if(pos[i+1]>-neg[j+1]){
                j++;
            }else{
                i++;
            }
            continue;
        }
        if(cur<0){
            i++;
        }
        else{
            j++;
        }
    }
    if(pos.size()>=2){
        if(abs(pos[0]+pos[1])<minval){
            minval=abs(pos[0]+pos[1]);
            coord = {pos[1],pos[0]};
        } 
    }
    if(neg.size()>=2){
        if(abs(neg[0]+neg[1])<minval){
            minval=abs(neg[0]+neg[1]);
            coord = {neg[0],neg[1]};
        } 
    }
    if(zero){
        if(pos[0]<-neg[0]){
            if(pos[0]<minval){
                cout<<"0 "<<pos[0];
                return 0;
            }
        }else{
            if(-neg[0]<minval){
                cout<<neg[0]<<" 0";
                return 0;
            }
        }
    }
    cout<<coord.second<<" "<<coord.first;
    return 0;
}