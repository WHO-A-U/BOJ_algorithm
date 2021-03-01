#include <bits/stdc++.h>
using namespace std;

vector<double> p;
double sp[2501][2501];
double mean[2501][2501][11];
double go(int left,int right , int strip){
    if(left>right)return 0.0;

    if(strip==1){
        if(left==0){
            return mean[left][right][strip]=sp[0][right];
        }else{
            return mean[left][right][strip]=sp[left][right]-sp[left][left-1];
        }
    }

    if(left==right)return mean[left][right][strip]=p[left];

    if(mean[left][right][strip]>0.0f ||abs(mean[left][right][strip]-(double)0)<FLT_EPSILON){
        return mean[left][right][strip];
    }

    double maxVal=0;

    for(int mid = left;right-mid>=strip-1;mid++){
        maxVal = max(maxVal , go(left,mid,1)+go(mid+1,right,strip-1));
    }

    return mean[left][right][strip]=maxVal;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin >> n >>k;
    double x;
    for(int i=0;i<n;i++){
        cin>>x;
        p.push_back((double)1-x);
    }

    for(int i=0;i<n;i++){
        sp[i][i]=p[i];
        for(int j=i+1;j<n;j++){
            sp[i][j]=sp[i][j-1]*p[j];
        }
        for(int j=i+1;j<n;j++){
            sp[i][j]+=sp[i][j-1];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int z=0;z<=k;z++)
                mean[i][j][z]=-1;
        }
    }


    cout<<fixed;
    cout.precision(6);

    cout<<go(0,n-1,k);

}