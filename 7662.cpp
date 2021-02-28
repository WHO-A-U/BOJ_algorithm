#include<iostream>
#include<map>
using ll=long long ;
using namespace std;
int main(){
    ll t,n,x;
    char c;
    cin>>t;
    while(t--){
        cin>>n;
        map<long long,int> m;
        map<long long,int>::iterator it,a,b;
        
        while(n--){
            cin>>c>>x;
            if(c=='I'){
                m[x]++;
            }else{
                if(m.size()==0)
                    continue;
                it = (x==1)?--m.end():m.begin();
                m[it->first]--;
                if(m[it->first]==0){
                    m.erase(it->first);
                }
            }
        }

        if(m.size()==0){
            cout<<"EMPTY\n";
        }else{
            a=m.begin();
            b=--m.end();
            cout<<b->first<<" "<<a->first<<"\n";
        }

    }

}