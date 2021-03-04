#include<deque>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int main(){  
    int n;
    cin>>n;
    deque<int> d;
    while(n--){
        string s;
        int x;
        cin>>s;
        if(s=="push"){
            cin>>x;
            d.push_back(x);
        }
        
        if(s=="pop"){
            if(d.empty()){
                cout<<"-1\n";
                continue;
            }
            cout<<d.front()<<"\n";
            d.pop_front();
        }

        if(s=="front"){
            if(d.empty()){
                cout<<"-1\n";
                continue;
            }
            cout<<d.front()<<"\n";
        }
        if(s=="back"){
            if(d.empty()){
                cout<<"-1\n";
                continue;
            }
            cout<<d.back()<<"\n";
            
        }
        if(s=="size"){
            cout<<d.size()<<"\n";
        }
        if(s=="empty"){
            cout<<d.empty()<<"\n";

        }
    }
}