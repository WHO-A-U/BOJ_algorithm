#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int d[1001][1001];
int Alen,Blen=0;
string A,B;
int maxsc(int i,int j){
    if (d[i][j]>=0)
        return d[i][j];
    if(i == Alen || j==Blen)
        return d[i][j]=0;
    return d[i][j]=max(maxsc(i+1,j),max(maxsc(i,j+1), maxsc(i+1,j+1)+(A[i]==B[j]?1:0) ) );
}
int main(){
    for(int i=0;i<1001;i++)
        for(int j=0;j<1001;j++)
            d[i][j]=-1;
    cin>>A>>B;
    Alen=A.length();
    Blen=B.length();
    cout<<maxsc(0,0);
}