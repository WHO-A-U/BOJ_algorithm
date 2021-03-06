#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
using namespace std;

int main(){
    int t,n;
    cin>>t;
    string a,b;
    while(t--){
        cin>>n;
        map<string,int> m;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            m[b]++;
        }

        int all=1;
        for(auto it = m.begin();it!=m.end();it++){
            all*=((it->second)+1);
        }
        all--;
        cout<<all<<"\n";
    }
}