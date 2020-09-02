#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int d[52][10];
vector<int> num;
int n,ans=0;
int tmp=0;
int l[4]; //0 홈 1 1루  2 2루  3 3루 
void pushL(){
    tmp+=l[3];
    l[3]=l[2];
    l[2]=l[1];
    l[1]=l[0];
    l[0]=0;
}
void play(){
    tmp=0;
    int j=0;
    for(int i=0;i<n;i++){
        for(int z=0;z<4;z++)
            l[z]=0;
        int life=3;
        while(life!=0){
            if(j>=9)
                j=0;
            int curPlayer = num[j];
            if(d[i][curPlayer]>0){
                l[0]=1;
                for(int k=0;k<d[i][curPlayer];k++){
                    pushL();
                }
            }else{
                life--;
            }
            j++;
        }
    }
    ans=max(ans,tmp);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<9;j++){
            cin>>d[i][j];
        }
    }
    for(int i=0;i<9;i++){
        num.push_back(i);
    }
    do{
        if(num[3]==0){
            play();
        }
    }while(next_permutation(num.begin(),num.end()));
    cout<<ans;
    return 0;
}