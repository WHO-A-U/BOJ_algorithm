#include<iostream>
#include<deque>
using namespace std;
int main(){
    int n;
    cin>>n;
    deque<int> d;
    for(int i=1;i<=n;i++){
        d.push_front(i);
    }
    while(d.size()>1){
        d.pop_back();
        d.push_front(d.back());
        d.pop_back();
    }
    cout<<d.front();
}