#include<iostream>
#include<vector>
using namespace std;
bool isP[1000001];
vector<int> P;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    for(int i=2;i<=1000000;i++)
        isP[i]=true;
    P.push_back(2);
    for(int i=3;i<=1000000;i++){
        if(isP[i]==false)
            continue;
        else{
            for(int j=2;j*j<=i;j++){
                if(i%j==0){
                    isP[i]=false;
                    break;
                }
            }
            if(isP[i]==false){
                for(int j=i*2;j<=1000000;j+=i)
                    isP[j]=false;
            }
            else{
                P.push_back(i);
            }

        }
    }
    while(1){
        cin>>x;
        if(x==0)
            break;
        int flag=0;
        for(int i=0;P[i]<=(x/2);i++){
            if(isP[x-P[i]]==true)
            {
                cout<<x<<" = "<<P[i]<<" + "<<x-P[i]<<'\n';
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"Goldbach's conjecture is wrong.\n";
    }
}