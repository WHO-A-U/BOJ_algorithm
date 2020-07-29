#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool plandrom[2501][2501];
int d[2501];
int main(){
    string str;
    cin>>str;
    int n=str.length();
    for(int i=0;i<n;i++)plandrom[i][i]=true;
    for(int i=0;i<n-1;i++)
        if(str[i]==str[i+1])
            plandrom[i][i+1]=true;
    for(int i=2;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(str[j]==str[j+i]&&plandrom[j+1][j+i-1])
                plandrom[j][i+j]=true;
        }
    }
    d[0]=1;
    for(int i=1;i<n;i++){
        int minval=0x3f3f3f3f;
        for(int j=0;j<=i;j++){
            if(plandrom[j][i]){
                if(j==0)
                    minval=1;
                else
                    minval=min(minval,d[j-1]+1);
            }
        }
        d[i]=minval;
    }
    cout<<d[n-1];
}