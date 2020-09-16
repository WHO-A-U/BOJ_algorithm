#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<deque>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    string str;
    cin>>n>>m;
    n=(n*2+1);
    cin>>str;
    bool start=false;
    deque<char> deq;
    int cnt=0;
    for(int i=0;i<str.length();i++){
        if(!start&&str[i]=='I'){
            start=true;
            deq.clear();
            deq.push_back('I');
        }
        else if(start){
            if(str[i]!=deq.back()){
                deq.push_back(str[i]);
                if(deq.size()==n){
                    cnt++;
                    deq.pop_back();
                    deq.pop_back();
                }
            }else if(str[i]=='I'){
                start=true;
                deq.clear();
                deq.push_back('I');
            }else{
                start=false;
                deq.clear();
            }
        }
    }
    cout<<cnt;
}

