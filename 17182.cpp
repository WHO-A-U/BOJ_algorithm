#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#define INF 0x3f3f3f3f
using namespace std;
int d[11][11];
int dist[1<<10];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,start;
    cin>>n>>start;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];
        }
    }
    
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    vector<int> arr;
    arr.push_back(start);
    for(int i=0;i<n;i++){
        if(i!=start)
            arr.push_back(i);
    }
    int minVal=INF;
    int val;
    do{
        val=0;
        for(int i=1;i<arr.size();i++){
            int a = arr[i-1];
            int b = arr[i];
            val+=d[a][b];
        }
        minVal = min(minVal , val);
    }while(next_permutation(arr.begin()+1,arr.end()));

    cout<<minVal;
}