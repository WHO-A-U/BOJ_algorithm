#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
vector<long long > ans;
int n;
bool isPrime(long long num){
    if(num==0||num==1)
        return false;
    bool flag=true;
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            flag=false;
            break;
        }
    }
    return flag;
}
void go(int k,long    long num){
    if(k==n){
        ans.push_back(num);
        return;
    }
    for(int i=0;i<10;i++){
        long long tmp = num*10+i;
        if(isPrime(tmp)){
            go(k+1,tmp);
        }
    }
}
int main(){
    cin>>n;
    go(0,0);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
}


// void calprime(int k){
//     auto end = pow(10,k);
//     long long a,b=1;
//     for(int i=0;i<k;i++)b*=10;
//     a=b/10;
//     p[1]=false;
//     for(int i=2;i*i<end;i++){
//         if(p[i]){
//             bool isPrime=true;
//             for(int j=2;j*j<=i;j++){
//                 if(i%j==0){
//                     isPrime=false;
//                     break;
//                 }
//             }
//             if(!isPrime){
//                 p[i]=false;
//                 for(int j=i*2;j<end;j+=i){
//                     p[j]=false;
//                 }
//             }
//         }
//     }
// }
// int main(){
//     memset(p,true,sizeof(p));
//     cin>>n;
//     calprime(n);
    
//     cout<<"end";
// }