#include<iostream>
#include<deque>
#include<algorithm>
#include<cstring>
using namespace std;
deque<int> d;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        string oper,arr;
        cin>>oper;
        // cout<<oper;
        cin>>n;
        cin>>arr;
        int tmp=0;
        bool head=true,number=false;
        bool isError=false;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>='0'&&arr[i]<='9'){
                tmp*=10;
                tmp+=(arr[i]-'0');
                number=true;
            }
            else{
                if(number){
                    d.push_back(tmp);
                    // cout<<"!"<<tmp<<"!";
                    tmp=0;
                }
                number=false;
            }
        }
        for(int i=0;i<oper.length();i++){
            if(oper[i]=='D'){
                if(d.size()==0){
                    isError=true;
                    cout<<"error\n";
                    break;
                }
                if(head)
                    d.pop_front();
                else
                    d.pop_back();
            }else{
                head=!head;
            }
        }
        if(!isError){
            cout<<"[";
            if(head){
                while(d.size()>1){
                    cout<<d.front()<<",";
                    d.pop_front();
                }
                if(d.size()==1){
                    cout<<d.front();
                    d.pop_front();
                }
            }
            else{
                while(d.size()>1){
                    cout<<d.back()<<",";
                    d.pop_back();
                }
                if(d.size()==1){
                    cout<<d.back();
                    d.pop_back();
                }
            }
            cout<<"]\n";
        }
    }

}