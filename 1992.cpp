#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char d[65][65];
void print(int rs,int re,int cs,int ce){
    if(re-rs==1&&ce-cs==1){
        cout<<d[rs][cs];
        return ;
    }
    bool flag=true;
    char tmp=d[rs][cs];
    for(int i=rs;i<re;i++){
        for(int j=cs;j<ce;j++){
            if(tmp!=d[i][j]){
                flag=false;
                break;
            }
        }
        if(!flag)
            break;
    }
    if(flag){
        cout<<d[rs][cs];
    }
    else{
        cout<<"(";
        int rm = (re-rs)/2;
        int cm = (ce-cs)/2;
        print(rs,rs+rm,cs,cs+cm);
        print(rs,rs+rm,cs+cm,ce);
        print(rs+rm,re,cs,cs+cm);
        print(rs+rm,re,cs+cm,ce);
        cout<<")";
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        for(int j=0;j<n;j++){
            d[i][j]=str[j];
        }
    }
    print(0,n,0,n);
}