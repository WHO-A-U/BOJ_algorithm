#include<deque>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int main(){  
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    deque<int> d;
    while(n--){
        string s;
        int x;
        cin>>s;
        if(s=="push_back"){
            cin>>x;
            d.push_back(x);
        }
        if(s=="push_front"){
            cin>>x;
            d.push_front(x);
        }
        
        if(s=="pop_front"){
            if(d.empty()){
                cout<<"-1\n";
                continue;
            }
            cout<<d.front()<<"\n";
            d.pop_front();
        }
        if(s=="pop_back"){
            if(d.empty()){
                cout<<"-1\n";
                continue;
            }
            cout<<d.back()<<"\n";
            d.pop_back();
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