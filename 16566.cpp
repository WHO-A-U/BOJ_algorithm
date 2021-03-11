#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int p[4000001];
int find(int x){
    if(p[x]==x){
        return x;
    }
    return p[x]=find(p[x]);
}
void erase(int x){
    p[x]=find(x+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k,x;
    cin>>n>>m>>k;
    int j=0;
    vector<int> d(m);
    for(int i=0;i<m;i++){
        cin>>d[i];
    }
    sort(d.begin(),d.end());

    for(int i=0;i<m;i++){
        x=d[i];
        for(;j<x;j++){
            p[j]=x;
        }
        p[x]=x;
        j=x+1;
    // cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    // for(int i=0;i<11;i++){
    //     printf("%d : %d\n",i,p[i]);
    // }
    // cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    }


    for(int i=0;i<k;i++){
        cin>>x;
        x = find(x+1);
        cout<<x<<"\n";
        erase(x);
    }



    

}