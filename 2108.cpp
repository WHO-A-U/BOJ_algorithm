#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
//-4000<= 0 <= 4000
//0<=8000
int f[8001];
vector<int> order;
int main()
{
    int n;
    cin>>n;
    int M=-4000,m=4000,sum=0,x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        order.push_back(x);
        sum+=x;
        m=min(m,x);
        M=max(M,x);
        f[x+4000]++;
    }
    sort(order.begin(),order.end());
    float a1=(float)sum/(float)n;
    int mid=order[n/2];
    int many=0;
    for(int i=0;i<8001;i++){
        if(f[many]<f[i])
        {
            many=i;
        }
    }
    vector<int> manys;
    for(int i=0;i<8001;i++){
        if(f[i]==f[many]){
            manys.push_back(i-4000);
        }
    }
    if(manys.size()>1)
        many=manys[1];
    else
        many=manys[0];
    cout<<round(a1)<<'\n'<<mid<<'\n'<<many<<'\n'<<M-m;
    
}