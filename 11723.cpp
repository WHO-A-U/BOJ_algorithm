#include<iostream>
#include<set>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin>>n;
    string s;
    int bitsss=0;
    while(n--){
        cin>>s;
        if(s=="add"){
            cin>>x;
            bitsss|=(1<<x);
        }
        if(s=="remove"){
            cin>>x;
            bitsss&=~(1<<x);
        }
        if(s=="check"){
            cin>>x;
            cout<<((bitsss&(1<<x))>0?1:0)<<"\n";
        }
        if(s=="toggle"){
            cin>>x;
            bitsss^=(1<<x);
        }
        if(s=="all"){
            bitsss=(1<<21)-1;
        }
        if(s=="empty"){
            bitsss=0;
        }
    }
}